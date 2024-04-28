def row_weights(v):
    return sum(v[i] for i in range(0, len(v), 2)), sum(v[i] for i in range(1, len(v), 2))
