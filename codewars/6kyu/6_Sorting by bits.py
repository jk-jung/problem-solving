def sort_by_bit(v):
    v.sort(key=lambda x: (bin(x).count('1'), x))