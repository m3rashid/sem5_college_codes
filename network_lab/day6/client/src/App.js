import React from "react";
import { io } from "socket.io-client";

const SERVER_ROOT_URL = "http://localhost:5000";
const socket = io(`${SERVER_ROOT_URL}`);

const Chat = () => {
  const [message, setMessage] = React.useState("");
  const [allChats, setAllChats] = React.useState([]);

  React.useEffect(() => {
    socket.emit("new-user-in-chat", {});
    return () => {
      socket.emit("user-left-the-chat");
    };
  }, []);

  const sendMessage = () => {};

  React.useEffect(() => {
    if (!socket) return;

    socket.on("receive-message", (data) => {
      const newChat = allChats.find((chat) => chat.id === data.id);
      if (!newChat) {
        setAllChats((prev) => [...prev, data]);
      }
    });

    socket.on("user-joined-chat", (data) => {
      console.log(data);
    });

    return () => {
      socket.off("receive-message");
      socket.off("user-joined-chat");
      socket.off("user-left-chat");
    };
  });

  return (
    <>
      <div>
        <div></div>
        <div className="flex flex-row justify-between items-center pr-2 md:px-2">
          <input type="text" name="msg" value={message} />
          <button onClick={sendMessage}>Submit</button>
        </div>
      </div>
    </>
  );
};

export default Chat;
