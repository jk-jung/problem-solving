def incrementer(a):
    return [(a[i] + i + 1) % 10 for i in range(len(a))]