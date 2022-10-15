def count_of_heads(x, n, swings):
    for i in range(swings):
        n *= i + 1
        x = x + n - 1
    return x
