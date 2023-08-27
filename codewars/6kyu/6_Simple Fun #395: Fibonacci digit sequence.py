def find(a,b,n):
    s = str(a) + str(b)
    t = {s: 0}

    while True:
        s += str(int(s[-1]) + int(s[-2]))
        k = s[-2:]
        if k in t:
            x = t[k]
            if n < x: return int(s[n])
            m = len(s) - 2 - x
            return int(s[x:][(n - x) % m])
        t[k] = len(s) - 2
