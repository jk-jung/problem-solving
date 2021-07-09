def rot13(message):
    def shift(x, b):
        return chr((ord(x) - ord(b) + 13) % 26 + ord(b))

    r = ''
    for i in message:
        if 'a' <= i and i <= 'z': r += shift(i, 'a')
        elif 'A' <= i and i <= 'Z': r += shift(i, 'A')
        else: r += i
    return r
