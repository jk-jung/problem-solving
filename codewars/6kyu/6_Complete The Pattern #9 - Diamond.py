def pattern(n):
    s = '1234567890' * n
    r = []
    for i in range(1, n + 1):
        a = s[:i] + s[:i - 1][::-1]
        r.append(a.center(n + n - 1))
    r += r[:-1][::-1]
    return '\n'.join(r)
