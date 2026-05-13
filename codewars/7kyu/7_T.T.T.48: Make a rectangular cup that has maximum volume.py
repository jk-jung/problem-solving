def maximum_volume(n):
    return max(i * (n - i - i) ** 2 for i in range(1, n // 2))
