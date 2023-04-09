def create_n_dimensional_array(n, size):
    v = [f'level {n}'] * size
    for i in range(1, n):
        v = [v] * size
    return v
