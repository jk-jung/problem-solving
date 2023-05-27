def is_divisible_by_6(s):
    r = []
    def go(x, t=''):
        if x == len(s):
            if int(t) % 6 == 0: r.append(t)
        elif s[x] == '*':
            for i in range(10):
                go(x + 1, t + str(i))
        else:
            go(x + 1, t + s[x])
    go(0, '')
    return r
