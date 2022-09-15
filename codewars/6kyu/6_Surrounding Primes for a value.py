p = [0 for i in range(200000)]
pr = []
for i in range(2, 200000):
    if p[i] == 0:
        pr.append(i)
        for j in range(i, 200000, i):
            p[j] = 1


def prime_bef_aft(n):
    for i in range(len(pr)):
        if pr[i] > n:
            return [pr[i - (2 if n in pr else 1)], pr[i]]
