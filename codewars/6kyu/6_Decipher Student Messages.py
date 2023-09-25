def decipher_message(s):
    n = int(len(s) ** .5)
    r = ''
    for i in range(n):
        for j in range(n):
            r += s[j * n + i]
    return r
