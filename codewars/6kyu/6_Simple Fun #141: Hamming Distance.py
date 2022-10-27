def hamming_distance(a, b):
    return sum((a >> i & 1) != (b >> i & 1) for i in range(30))
