def sort_by_bit(v):
    return sorted(v, key=lambda x: (bin(x).count('1'), x))