def check_palindrome(text):
    rev = ""
    arr = list(text)[::-1]
    for ch in arr:
        rev += ch

    if rev == text:
        print(f"{text} : palindrome\n")
        return True
    else:
        print(f"{text} : not palindrome\n")
        return False


if __name__ == "__main__":
    check_palindrome("hello")
    check_palindrome("malayalam")
    check_palindrome("121")
    check_palindrome("1234321")
