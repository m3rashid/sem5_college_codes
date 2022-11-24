def generateKey(string, key):
    key = list(key)
    if len(string) == len(key):
        return key
    else:
        for i in range(len(string) - len(key)):
            key.append(key[i % len(key)])
    return "".join(key).upper()


def encrypt(string, key):
    string = string.upper()
    cipher_text = []

    for i in range(len(string)):
        if string[i] == " ":
            cipher_text.append(string[i])
        else:
            x = (ord(string[i]) + ord(key[i])) % 26
            x += ord('A')
            cipher_text.append(chr(x))
    return "".join(cipher_text)


def decrypt(cipher_text, key):
    cipher_text = cipher_text.upper()
    orig_text = []

    for i in range(len(cipher_text)):
        if cipher_text[i] == " ":
            orig_text.append(cipher_text[i])
        else:
            x = (ord(cipher_text[i]) - ord(key[i]) + 26) % 26
            x += ord('A')
            orig_text.append(chr(x))
    return "".join(orig_text)


if __name__ == "__main__":
    _string = input("Enter string: ")
    _keyword = input("Enter keyword: ")

    _key = generateKey(_string, _keyword)
    print(_key)
    ct = encrypt(_string, _key)
    print("Ciphertext :", ct)
    print("Original/Decrypted Text :", decrypt(ct, _key))
