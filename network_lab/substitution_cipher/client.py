import threading
import socket
import cipher as substitution_cipher

alias = input('Enter username: ')
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('127.0.0.1', 59000))


def client_receive():
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            if message == "alias?":
                client.send(alias.encode('utf-8'))
        except:
            print('Error!')
            client.close()
            break


def client_send():
    while True:
        text = input("Enter Message: ")
        key = input("Enter key: ")
        enc = substitution_cipher.encrypt(text, int(key))
        print(f"Encrypted: >>> {enc} >>>")
        message = f'{alias}: {enc} : {key}'
        client.send(message.encode('utf-8'))


if __name__ == "__main__":
    print("====================== CLIENT ====================== ")
    print()
    receive_thread = threading.Thread(target=client_receive)
    receive_thread.start()
    send_thread = threading.Thread(target=client_send)
    send_thread.start()
