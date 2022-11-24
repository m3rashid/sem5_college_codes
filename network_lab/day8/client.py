import threading
import socket
from railFence import encrypt


KEY = 2
alias = input('Enter username: ')
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('127.0.0.1', 59000))


def client_receive():
  global KEY

  while True:
    try:
      message = client.recv(1024).decode('utf-8')
      if message == "alias?":
        client.send(alias.encode('utf-8'))
      else:
          key = message.split(" ")[1]
          if key.isnumeric():
            KEY = int(key)
          else:
            print(f"Received: <<< {message} <<<")

    except:
      print('Error!')
      client.close()
      break


def client_send():
  while True:
    text = input("")
    enc = encrypt(text, KEY)
    print(f"Encrypted: >>> {enc} >>>")
    message = f'{alias}: {enc}'
    client.send(message.encode('utf-8'))


if __name__ == "__main__":
  print("====================== CLIENT ====================== ")
  print()
  receive_thread = threading.Thread(target=client_receive)
  receive_thread.start()
  send_thread = threading.Thread(target=client_send)
  send_thread.start()
