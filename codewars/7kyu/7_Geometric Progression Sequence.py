def geometric_sequence_elements(a, r, n):
    r = [a * r ** i for i in range(n)]
    return ', '.join(map(str, r))