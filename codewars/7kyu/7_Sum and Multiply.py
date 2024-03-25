def sum_and_multiply(a, b):
    for i in range(0, a + 1):
        if i * (a - i) == b:
            return [i, a - i]
