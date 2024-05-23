def sum_of_n(n):
    t = [0]
    s = 0
    for i in range(abs(n)):
        s += i + 1
        t.append(s)
    if n < 0: return [-x for x in t]
    return t