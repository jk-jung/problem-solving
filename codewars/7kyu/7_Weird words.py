def next_letter(s):
    def f(x):
        if x.islower(): return chr((ord(x) - ord('a') + 1) % 26 + ord('a'))
        if x.isupper(): return chr((ord(x) - ord('A') + 1) % 26 + ord('A'))
        return x
    return ''.join(f(x) for x in s)
