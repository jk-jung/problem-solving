def one_down(txt):
    if not isinstance(txt, str): return "Input is not a string"
    r = ''
    for x in txt:
        if x.isalpha():
            if x.isupper():
                r += chr((ord(x) - ord('A') - 1) % 26 + ord('A'))
            else:
                r += chr((ord(x) - ord('a') - 1) % 26 + ord('a'))
        else:
            r += x
    return r
