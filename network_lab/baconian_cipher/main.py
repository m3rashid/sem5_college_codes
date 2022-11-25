lookup = {'A': 'aaaaa', 'B': 'aaaab', 'C': 'aaaba', 'D': 'aaabb', 'E': 'aabaa',
    'F': 'aabab', 'G': 'aabba', 'H': 'aabbb', 'I': 'abaaa', 'J': 'abaab',
    'K': 'ababa', 'L': 'ababb', 'M': 'abbaa', 'N': 'abbab', 'O': 'abbba',
    'P': 'abbbb', 'Q': 'baaaa', 'R': 'baaab', 'S': 'baaba', 'T': 'baabb',
    'U': 'babaa', 'V': 'babab', 'W': 'babba', 'X': 'babbb', 'Y': 'bbaaa', 'Z': 'bbaab'}

def encrypt(message):
  cipher = ''
  for letter in message:
    if(letter != ' '):
      cipher += lookup[letter]
    else:
      cipher += ' '
  return cipher


def decrypt(message):
  decipher = ''
  i = 0

  while True:
    if(i < len(message)-4):
      substr = message[i:i + 5]
      if(substr[0] != ' '):
        decipher += list(lookup.keys()
                )[list(lookup.values()).index(substr)]
        i += 5 
      else:
        decipher += ' '
        i += 1
    else:
      break
  return decipher


def main():
  message1 = input("Enter your message 1: ")
  encrypted1 = encrypt(message1.upper())
  print(encrypted1)
  decrypted1 = decrypt(encrypted1)
  print(decrypted1)

  message2 = input("Enter your message 2: ")
  encrypted2 = encrypt(message2.upper())
  print(encrypted2)
  decrypted2 = decrypt(encrypted2)
  print(decrypted2)


if __name__ == '__main__':
  main()
