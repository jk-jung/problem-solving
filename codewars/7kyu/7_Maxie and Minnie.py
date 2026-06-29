def swap(a):
    a = list(str(a))
    r = []
    for i in range(len(a)):
        for j in range(len(a)):
            b = a[:]
            b[i], b[j] = b[j], b[i]
            if b[0] != "0":
                r.append(int("".join(b)))
    r.sort()
    return r[-1], r[0]
