def toexuto(text):
    r = ''
    for x in text:
        r += x
        if x.lower() not in 'aeiou' and 'a' <= x.lower() <= 'z':
            t = ord(x.lower())
            while True:
                if chr(t) in 'aeiou':
                    r += chr(t)
                    break
                t -= 1

    return r