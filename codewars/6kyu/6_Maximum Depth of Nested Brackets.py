def strings_in_max_depth(s):
    st, t = 0, ''
    r = []
    for x in s:
        if x == '(':
            st += 1
            t = ''
        elif x == ')':
            r.append((st, t))
            st -= 1
        else: t += x

    if not r: return [s]
    k = max(r)[0]
    return [x[-1] for x in r if x[0] == k]
