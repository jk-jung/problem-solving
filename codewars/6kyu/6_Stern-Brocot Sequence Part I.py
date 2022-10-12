def stern_brocot(n):
    if n == 1: return 0
    a = [1, 1]
    pos = 2
    for i in range(0, 1111111111):
        a.append(a[i] + a[i + 1])
        a.append(a[i + 1])
        if a[i] + a[i + 1] == n: return pos
        pos += 2
