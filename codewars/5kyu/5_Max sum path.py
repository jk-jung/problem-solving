def max_sum_path(l1, l2):
    a, b = 0, 0
    n, m = len(l1), len(l2)
    common = set(l1) & set(l2)
    r = sum(common)
    common.add(1e20)

    for x in sorted(common):
        sum_a, sum_b = 0, 0
        while a < n and l1[a] < x: sum_a, a = sum_a + l1[a], a + 1
        while b < m and l2[b] < x: sum_b, b = sum_b + l2[b], b + 1
        r += max(sum_a, sum_b)
        a, b = a + 1, b + 1

    return r