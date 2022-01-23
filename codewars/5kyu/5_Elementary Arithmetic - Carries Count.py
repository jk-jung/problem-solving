def solve(s):
    ss = []
    for x in s.split('\n'):
        x, y = [reversed(_) for _ in x.split(' ')]
        r, c = 0, 0
        for a, b in zip(x, y):
            if int(a) + int(b) + c > 9:
                c = 1
                r += 1
            else: c = 0

        if r == 0:
            ss.append('No carry operation')
        else:
            ss.append('%d carry operations' % r)

    return '\n'.join(ss)