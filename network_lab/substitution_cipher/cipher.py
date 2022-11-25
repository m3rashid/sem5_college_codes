import string

all_letters = string.ascii_letters
dict1 = {}


def encrypt(plain_txt, key):
    for i in range(len(all_letters)):
        dict1[all_letters[i]] = all_letters[(i + key) % len(all_letters)]
    cipher_txt = []
    for char in plain_txt:
        if char in all_letters:
            temp = dict1[char]
            cipher_txt.append(temp)
        else:
            temp = char
            cipher_txt.append(temp)
    return "".join(cipher_txt)


def decrypt(cipher_txt, key):
    dict2 = {}
    for i in range(len(all_letters)):
        dict2[all_letters[i]] = all_letters[(i - key) % (len(all_letters))]

    decrypt_txt = []
    for char in cipher_txt:
        if char in all_letters:
            temp = dict2[char]
            decrypt_txt.append(temp)
        else:
            temp = char
            decrypt_txt.append(temp)

    return "".join(decrypt_txt)


if __name__ == "__main__":
    message = input("Enter your message (string): ")
    _key = input("Enter key (integer): ")
    encrypted = encrypt(message, int(_key))
    decrypted = decrypt(encrypted, int(_key))
    print("original message: ", message)
    print("Encrypted message: ", encrypted)
    print("Decrypted message: ", decrypted)
