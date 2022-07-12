def swap(s, n):
    r, i = '', 0
    t = []
    while n:
        t.append(n & 1)
        n //= 2
    t = list(reversed(t))
    if not t:
        t = [0]

    for x in s:
        if x.isalpha():
            if t[i]:
                r += x.upper() if x.islower() else x.lower()
            else:
                r += x
            i = (i + 1) % len(t)
        else:
            r += x
    return r