n = 15486705
p = [1 for _ in range(n)]
r = []
for i in range(2, n):
    if p[i]:
        r.append(i)
        for j in range(i + i, n, i):
            p[j] = 0


class Primes:
    @staticmethod
    def stream():
        for x in r:
            yield x
