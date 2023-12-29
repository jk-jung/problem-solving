def race_podium(n):
    for a in range(n):
        b = a - 1
        c = n - a - b
        if a > b > c > 0: return (b, a, c)
    for a in range(n):
        b = a - 2
        c = n - a - b
        if a > b > c > 0: return (b, a, c)