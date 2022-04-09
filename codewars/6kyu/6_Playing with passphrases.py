def play_pass(s, n):
    r = ''
    for i, x in enumerate(s):
        if x.isalpha():
            x = x.lower()
            x = chr((ord(x) - ord('a') + n) % 26 + ord('a'))
            if i % 2 == 0: x = x.upper()
            r += x
        elif x.isdigit():
            r += str(9 - int(x))
        else:
            r += x
    return r[::-1]