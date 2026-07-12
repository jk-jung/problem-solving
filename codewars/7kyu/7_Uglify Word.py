def uglify_word(s):
    r = ""
    i = 0
    for x in s:
        if x.isalpha():
            if i % 2:
                r += x.lower()
            else:
                r += x.upper()
            i += 1
        else:
            r += x
            i = 0
    return r
