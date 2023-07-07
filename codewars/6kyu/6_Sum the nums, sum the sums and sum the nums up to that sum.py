def sum_of_sums(n):
    n = (n * (n + 1) * (2 * n + 1) // 6 + n * (n + 1) // 2) // 2
    return n * (n + 1) // 2
