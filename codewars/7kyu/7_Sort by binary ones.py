def sort_by_binary_ones (v):
    return sorted(v, key=lambda x:(-bin(x).count('1'), x))
