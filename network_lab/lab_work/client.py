import socket
import palindrome

HOST = '127.0.0.1'
PORT = 59000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))


def handle_client():
    global msg_to_send

    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            print(f"message got: {message}")
            is_palindrome = palindrome.check_palindrome(message)
            msg_to_send = ""
            if is_palindrome:
                msg_to_send = f"{message} is a palindrome"
            else:
                msg_to_send = f"{message} is not a palindrome"

            client.send(msg_to_send.encode('utf-8'))
        except:
            print('Error!')
            client.close()
            break


if __name__ == "__main__":
    print("====================== CLIENT ====================== ")
    print(f"Client active on: {HOST} : {PORT}")
    print()
    handle_client()
