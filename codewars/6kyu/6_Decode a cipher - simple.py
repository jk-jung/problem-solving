import string
def decode(v, b, c):
    d = 0
    r = ''
    for x in v:
        for e in string.ascii_letters:
            t = (string.ascii_letters.index(e)+b+c)%(b*c)+d
            if t == x:
                r += e
                d = t
                break
    return r
