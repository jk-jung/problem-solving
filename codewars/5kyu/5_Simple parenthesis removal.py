def solve(s):
    v = []
    for x in s:
        if x == ')':
            t = []
            while v[-1] != '(':
                t.append(v[-1])
                v.pop(-1)
            v.pop(-1)
            sign = v.pop(-1) if v and v[-1] != '(' else '+'
            t = t[::-1]
            if t and t[0] not in '+-': t = ['+'] + t
            if sign == '-' and t:
                for y in t:
                    if y in '+-': v.append('-' if y == '+' else '+')
                    else: v.append(y)
            else:
                v += t
        else: v.append(x)
    r = ''.join(v)
    if r and r[0] == '+': r = r[1:]
    return r