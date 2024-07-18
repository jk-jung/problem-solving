def hyperfact(a):
    r = 1
    for i in range(1, a + 1):
        for j in range(i):
            r = (r * i) % 1000000007
    return r
