def animals(a, b):
    for i in range(a + 1):
        if i * 2 + (a - i) * 4 == b:
            return (i, a - i)
    return "No solutions"
