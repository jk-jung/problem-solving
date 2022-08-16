def tower_builder(n, block_size):
    w, h = block_size
    m = w * (2 * n - 1)
    r = []
    for i in range(n):
        [r.append(('*' * w * (2 * i + 1)).center(m)) for j in range(h)]
    return r
