def closest(strng):
    v = [int(x) for x in strng.strip().split(' ') if x]

    def val(x):
        k = 0;
        while x:
            k += x % 10
            x //= 10
        return k

    r = []
    for i in range(len(v)):
        for j in range(len(v)):
            if i == j: continue
            t = [
                [val(v[i]), i, v[i]],
                [val(v[j]), j, v[j]]
            ]
            r.append((abs(t[0][0] - t[1][0]), sorted(t)))
    if len(r) == 0: return r
    return sorted(r)[0][1]
