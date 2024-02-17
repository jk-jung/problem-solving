def remove(text, what):
    r = ''
    for x in text:
        if x in what and what[x] > 0:
            what[x] -= 1
        else: r += x
    return r
