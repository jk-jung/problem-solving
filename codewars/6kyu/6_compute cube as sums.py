def find_summands(n):
    if n % 2:
        return [n * n + (x - n // 2) * 2 for x in range(n)]
    else:
        return [n * n + 1 + (x - n // 2) * 2 for x in range(n)]
