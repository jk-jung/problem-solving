def fibonacci(n):
    r = []
    for i in range(n):
        if i < 2: r.append(i)
        else: r.append(r[-1] + r[-2])
    return r
