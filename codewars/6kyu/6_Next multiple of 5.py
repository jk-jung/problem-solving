def next_multiple_of_five(n):
    r = []
    for i in range(0, 1000):
        t = len(bin(i)) - 2
        for j in range(10):
            k = (n << t + j) + i
            if k % 5 == 0 and k !=n:
                r.append(k)
    return min(r)
