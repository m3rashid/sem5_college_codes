import socket

HOST = '127.0.0.1'
PORT = 59000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen()


def handle_client(client):
    while True:
        try:
            msg = input("Enter string: ")
            client.send(msg.encode('utf-8'))
            message = client.recv(1024)
            if message:
                decoded = message.decode('utf-8')
                print(f"Received:  {decoded}\n")
        except:
            client.close()
            break


if __name__ == "__main__":
    print("====================== SERVER ====================== ")
    print(f"Server is listening on: {HOST} : {PORT}")
    print()
    client, address = server.accept()
    print(f'connection is established with {address}')
    handle_client(client)
