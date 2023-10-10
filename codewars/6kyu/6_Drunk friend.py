def decode(s):
    if not isinstance(s, str): return 'Input is not a string'
    r = ''
    for x in s:
        if x.isupper():
            r += chr((ord('A') - ord(x) + 25) % 26 + ord('A'))
        elif x.islower():
            r += chr((ord('a') - ord(x) + 25) % 26 + ord('a'))
        else: r += x
    return r