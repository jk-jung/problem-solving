def changer(s):
    r = ''
    for x in s:
        if x.isalpha():
            x = ord(x.lower())
            if x == ord('z'): x = 'a'
            else: x = chr(x + 1)
            if x in 'aeiou':
                r += x.upper()
            else: r += x
        else: r += x

    return r
