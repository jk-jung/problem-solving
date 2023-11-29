def euclidean_distance(a, b):
    return round((sum((x - y) ** 2 for x, y in zip(a, b))) ** .5, 2)
