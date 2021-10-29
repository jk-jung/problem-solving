def decode(data, w):
    if data[0] == 0:
        return sum([[v] * c for v, c in data[1]], [])
    return [data[1]] * w


def make(a, b, c):
    r = []
    for i in range(len(b)):
        v = [a[i], c[i]]
        if i > 0:
            v += [a[i-1], b[i-1], c[i-1]]
        if i < len(b) - 1:
            v += [a[i+1], b[i+1], c[i+1]]

        r.append(max(abs(b[i] - x) for x in v if x is not None))
    return r


def edge_detection(image):
    w, *v = image.split(' ')
    w = int(w)
    v = [(int(v[i]), int(v[i+1])) for i in range(0, len(v), 2)]
    print(w)

    remain = 0
    v2 = []
    line = []
    for val, cnt in v:
        if remain != 0:
            can = min(w - remain, cnt)
            line.append((val, can))

            remain += can
            cnt -= can

            if remain == w:
                remain = 0
                v2.append((0, line))
                line = []
        if cnt >= w:
            v2.append((1, val, cnt // w))
            cnt %= w
        if cnt > 0:
            line.append((val, cnt))
            remain = cnt

    r = []
    for i, data in enumerate(v2):
        if i == 0: before = [None] * w
        else: before = decode(v2[i-1], w)
        if i + 1 == len(v2): after = [None] * w
        else: after = decode(v2[i+1], w)

        if data[0] == 0:
            cur = decode(v2[i], w)
            r.append(make(before, cur, after))
        else:
            val, cnt = data[1:]
            cur = [val] * w

            if cnt == 1:
                r.append(make(before, cur, after))
            else:
                r.append(make(before, cur, cur))
                if cnt > 2: r.append((0, w * (cnt - 2)))
                r.append(make(cur, cur, after))

    rr = [[-1000, 0]]
    for x in r:
        if type(x) is list:
            for y in x:
                if rr[-1][0] == y:
                    rr[-1][1] += 1
                else:
                    rr.append([y, 1])
        else:
            if rr[-1][0] == x[0]:
                rr[-1][1] += x[1]
            else:
                rr.append(list(x))
    rr[0] = [w]
    return ' '.join([' '.join(str(x) for x in y) for y in rr])
