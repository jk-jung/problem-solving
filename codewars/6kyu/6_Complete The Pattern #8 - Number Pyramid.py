def pattern(n):
    r, m = [], n * 2 - 1
    s = ''
    for i in range(1, n + 1):
        c = str(i % 10)
        r.append((s + c + s[::-1]).center(m, ' '))
        s += c
    return '\n'.join(r)
