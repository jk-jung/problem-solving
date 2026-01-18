def each_cons(a, b):
    return [a[i : i + b] for i in range(len(a) - b + 1)]
