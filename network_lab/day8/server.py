import threading
import socket
import railFence

HOST = '127.0.0.1'
PORT = 59000
KEY = 3
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen()
allClients = []
aliases = []

print(f"Server is listening on: {HOST} : {PORT}")

def broadcast(message):
  for client in allClients:
    client.send(message)


def handle_client(client):
  while True:
    try:
      message = client.recv(1024)
      decoded = message.decode('utf-8').split(":")
      alias = decoded[0].strip()
      msg = decoded[1].strip()
      print(f"Received: <<< {msg} <<<")
      enc = f"{alias} {railFence.decrypt(msg, KEY)}"
      client.send(enc.encode('utf-8'))
      print(f"Decrypted: >>> {enc} >>>")
    except:
      index = allClients.index(client)
      allClients.remove(client)
      client.close()
      alias = aliases[index]
      broadcast(f'{alias} has left the chat room!'.encode('utf-8'))
      aliases.remove(alias)
      break


def receive():
    while True:
        client, address = server.accept()
        print(f'connection is established with {str(address)}')
        client.send('alias?'.encode('utf-8'))
        alias = client.recv(1024)
        aliases.append(alias)
        allClients.append(client)
        broadcast(f'{alias} has connected to the chat room'.encode('utf-8'))
        client.send(f'KEY {KEY}'.encode('utf-8'))
        thread = threading.Thread(target=handle_client, args=(client,))
        thread.start()


if __name__ == "__main__":
    print("====================== SERVER ====================== ")
    receive()
