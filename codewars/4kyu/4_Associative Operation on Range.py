def read(tre, n, op, s_, e_):
    s = s_ + n
    e = e_ + n - 1

    r1 = []
    r2 = []
    while s <= e:
        if s % 2 == 1:
            r1.append(tre[s])
            s += 1
        if e % 2 == 0:
            r2.append(tre[e])
            e -= 1
        s //= 2
        e //= 2

    r = r1 + list(reversed(r2))
    t = r[0]
    for i in range(1, len(r)):
        t = op(t, r[i])
    return t


def compute_ranges(arr, op, rs):
    n = 1
    while n < len(arr): n *= 2
    tre = [None for _ in range(n * 2)]

    for i in range(len(arr)):
        tre[i + n] = arr[i]

    for i in range(n - 1, 0, -1):
        if tre[i * 2] is None:
            tre[i] = tre[i * 2 + 1]
        elif tre[i * 2 + 1] is None:
            tre[i] = tre[i * 2]
        else:
            tre[i] = op(tre[i * 2], tre[i * 2 + 1])

    return [read(tre, n, op, *x) for x in rs]
