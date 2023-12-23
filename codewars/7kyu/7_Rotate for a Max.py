def max_rot(n):
    n = str(n)
    r = n
    for i in range(len(n)):
        n = n[:i] + n[i + 1:] + n[i]
        r = max(r, n)
    return int(r)
