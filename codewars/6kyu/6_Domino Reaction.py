def domino_reaction(s):
    r, ok = '', True
    for x in s:
        if x != '|': ok = False
        if ok and x == '|': r += '/'
        else: r += x
    return r
