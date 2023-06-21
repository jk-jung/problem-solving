d = [0]
s = [0]

for i in range(1, 1000001):
    s.append((s[-1] + d[-1]) % 1000000007)
    d.append((s[-1] + 3 * i * (i + 1) // 2) % 1000000007)


def find_x(n):
    return d[n]