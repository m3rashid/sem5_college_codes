const cors = require("cors");
const http = require("http");
const express = require("express");
const { Server } = require("socket.io");

const corsOrigin = ["http://localhost:3000", "http://localhost:3001"];

const { router: socketHandler } = require("./handler");

const app = express();
const server = http.createServer(app);

const io = new Server(server, {
  cors: {
    origin: corsOrigin,
    methods: ["GET", "POST"],
    credentials: true,
  },
});

io.on("connection", (socket) => {
  const data = {
    socket_status: "connected",
    socketId: socket.id,
    userId: socket.user.id,
  };

  socket.on("connect", () => console.log(data));
  return socketHandler(io, socket);
});

app.use(cors({ origin: "*", optionsSuccessStatus: 200 }));

app.get("/", (req, res) => {
  return res.send("Hello World");
});

app.get("/health", (req, res) => {
  const healthcheck = {
    uptime: process.uptime(),
    responseTime: process.hrtime(),
    message: "OK",
    timestamp: Date.now(),
  };
  try {
    return res.status(200).send(healthcheck);
  } catch (error) {
    healthcheck.message = error;
    return res.status(503).send(healthcheck);
  }
});

const PORT = process.env.PORT || 5000;

server.listen(PORT, () => console.log(`Server on http://localhost:${PORT}`));
