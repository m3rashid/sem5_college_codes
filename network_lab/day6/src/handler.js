const messages = [];

const router = (io, socket) => {
  socket.on("send-msg", ({ msg }) => {
    messages.push(msg);
    io.emit("msg-receive", msg);
  });

  socket.on("new-user-in-chat", () => {
    io.emit("user-joined-chat", messages);
  });
};

module.exports = {
  router,
};
