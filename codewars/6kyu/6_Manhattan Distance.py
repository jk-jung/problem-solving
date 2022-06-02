def manhattan_distance(a, b):
    return sum(abs(x - y) for x, y in zip(a, b))
