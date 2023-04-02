def toUnderScore(n):
    r = ''
    for x in n:
        if x.isupper() and r and r[-1] != '_':
            r += '_'
        elif r and x.isdigit() and not r[-1].isdigit() and r[-1] != '_':
            r += '_'
        r += x
    return r
