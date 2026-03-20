def breach_attempts(a, b, c):
    r = 0
    for x in a:
        if x > b:
            r += 1
        else:
            b += c
    return r
