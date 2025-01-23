def solve(s):
    r = ''
    t = [x for x in s if x != ' ']
    for x in s:
        if x == ' ':
            r += ' '
        else:
            r += t.pop()
    return r