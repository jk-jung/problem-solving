x = 'banana'

def go(i, k, s, r, t):
    if i == len(s):
        if k == len(x): r.append(t)
    else:
        go(i + 1, k, s, r, t + '-')
        if k < len(x) and x[k] == s[i]:
            go(i + 1, k + 1, s, r, t + s[i])

def bananas(s):
    r = []
    go(0, 0, s, r, '')
    return r