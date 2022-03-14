def pack_basket(n, s):
    d = [0 for _ in range(n + 1)]
    v = [int(x) for x in s.replace('dust', ' ').split(' ') if x]
    d[0] = 1
    r = 0
    for x in v:
        for i in range(n, -1, -1):
            if d[i] and i + x <= n:
                d[i + x] = 1
                r = max(r, i + x)
    return f'The basket weighs {r} kilograms'
