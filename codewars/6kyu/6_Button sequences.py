def button_sequences(a, b):
    def seg(s):
        r = []
        start, end = 1 << 30, -1
        for i, x in enumerate(s + '0'):
            if x == '1':
                start = min(start, i)
                end = i
            else:
                if end != -1:
                    r.append((start, end))
                    start, end = 1 << 30, -1
        return r
    a, b = seg(a), seg(b)
    b = [x for x in b if not any(y[0] <= x[0] and x[1] <= y[1] for y in a)]
    a = [x for x in a if not any(y[0] < x[0] and x[1] <= y[1] for y in b)]
    r = [(x[0], '1') for x in a] + [(x[0], 'B') for x in b]
    return ''.join([x[1] for x in sorted(r)]).replace('1', 'R')
