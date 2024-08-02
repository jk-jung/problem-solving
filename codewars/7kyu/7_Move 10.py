def move_ten(s):
    def f(x):
        return chr((ord(x) - ord('a') + 10) % 26 + ord('a'))
    return ''.join(map(f, s))