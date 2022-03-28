def triple_double(a, b):
    a, b = str(a), str(b)
    for i in range(0, 10):
        x = str(i)
        if x * 3 in a and x * 2 in b:
            return 1
    return 0
