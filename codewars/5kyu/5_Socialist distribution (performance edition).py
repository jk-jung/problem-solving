def distribution(lst, n):
    need = sum(0 if x > n else n - x for x in lst)

    s = n
    e = max(lst)
    r = s
    while s <= e:
        m = (s + e) // 2
        ss = sum(max(0, x - m) for x in lst)
        if ss >= need:
            s = m + 1
            r = m
        else: e = m - 1

    v = []
    for x in lst:
        if x < n: v.append(n)
        elif x > r:
            need -= (x - r)
            v.append(r)
        else: v.append(x)
    for i in range(len(v) -1, -1, -1):
        if need < 0 and lst[i] > r:
            v[i] += 1
            need += 1

    return v