u = [0 for _ in range(1000000)]
u[1] = u[2] = 1
for i in range(3, 1000000):
    u[i] = u[i - u[i - 1]] + u[i - u[i - 2]]


def length_sup_u_k(n, k):
    return len([x for x in u[:n + 1] if x >= k])


def comp(n):
    return len([i for i in range(10, n) if u[i] > u[i + 1]])
