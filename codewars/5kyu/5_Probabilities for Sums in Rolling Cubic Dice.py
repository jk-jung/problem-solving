def rolldice_sum_prob(x, c):
    d0 = [0 for _ in range(x + 1)]
    d0[0] = 1

    for i in range(c):
        d1 = [0 for _ in range(x + 1)]
        for j in range(x + 1):
            for k in range(1, 7):
                if j - k >= 0:
                    d1[j] += d0[j - k] / 6
        d0 = d1
    return d0[x]
