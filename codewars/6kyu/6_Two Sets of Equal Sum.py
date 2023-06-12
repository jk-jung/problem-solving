def create_two_sets_of_equal_sum(n):
    m = n * (n + 1) // 2
    if m % 2 == 1: return []
    m //= 2
    r = {i for i in range(1, n + 1)}
    a = []

    for i in range(n, 0, -1):
        if m >= i:
            m -= i
            r.remove(i)
            a.append(i)

    return list(r), a
