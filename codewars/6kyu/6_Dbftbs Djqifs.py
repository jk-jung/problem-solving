def encryptor(key, message):
    def f(x):
        if x.isupper():
            return chr((ord(x) - ord('A') + key + 26) % 26 + ord('A'))
        elif x.islower():
            return chr((ord(x) - ord('a') + key + 26) % 26 + ord('a'))
        return x
    return ''.join(f(x) for x in message)