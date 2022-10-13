import re
import threading
import socket

host = '127.0.0.1'
port = 59000
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen()
allClients = []
aliases = []

print(f"Server is listening on: {host} : {port}")

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
            wholeType = tellTypeWhole(msg, alias)
            charByChar = tellTypeCharacterByCharacter(msg, alias)
            
            broadcast(charByChar.encode('utf-8'))
            broadcast(wholeType.encode('utf-8'))
            
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
        client.send('you are now connected!'.encode('utf-8'))
        thread = threading.Thread(target=handle_client, args=(client,))
        thread.start()


def tellTypeCharacterByCharacter (msg, alias):
    reg = re.compile('[@_!#$%^&*()<>?/|}{~:]')
    to_send = "===============\n"
    for ch in msg:
        if reg.match(ch):
            to_send  += f"{ch} is a special character\n"
        elif ch.isnumeric():
            to_send += f"{ch} is a number\n"
        else: 
            to_send += f"{ch} is a letter\n"
    print(to_send)
    return f"{alias}: {to_send} ===============\n\n"
           

def tellTypeWhole (msg, alias):
    msg_copy = msg;
    newMsg = ""
    if msg.isnumeric():
        newMsg = f"{msg} is a positive integer\n"
    elif msg_copy.replace('.', '', 1).isdigit():
        newMsg = f"{msg} is a floating point number"
    elif msg.lstrip('-+').isdigit():
        newMsg = f"{msg} is a negative integer"
    elif msg.isalpha() is False:
        newMsg = f"{msg} cotains a special character"
    else:
        newMsg = f"{msg} is a string"

    print(newMsg)
    return f"{alias}: {newMsg}"
                      
                      
if __name__ == "__main__":
    receive()
    