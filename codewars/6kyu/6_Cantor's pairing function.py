def cantor(n : int) -> str:
    idx, m = 1, 1
    while True:
        if idx <= n < idx + m:
            a = n - idx + 1
            b = m - a + 1
            if m % 2: a, b = b, a
            return f"{a}/{b}"
        idx += m
        m += 1
