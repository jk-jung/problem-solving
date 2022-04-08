def kebabize(s):
    r = ''
    for x in s:
        if x.isalpha():
            if x.isupper(): r += '-'
            r += x.lower()
    return r.strip('-')
