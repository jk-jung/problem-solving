r = [0 for _ in range(1000005)]
r[0] = 1

k = -1
for i in range(1, 1000001):
    r[i] = r[i - 1] + k * (4 * i + 2) * (i + 1) // 2
    k *= -1

def get_sum(n):
    return r[n]
