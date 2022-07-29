def max_pizza(x):
    if x < 0: return -1
    return sum(i for i in range(x + 1)) + 1