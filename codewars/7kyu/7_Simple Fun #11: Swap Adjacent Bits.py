def swap_adjacent_bits(n):
    r = 0
    for i in range(0, 30, 2):
        j = i + 1
        r |= (1 << i) * (n >> j & 1)
        r |= (1 << j) * (n >> i & 1)
    return r