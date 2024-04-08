def count_duplicates(a,b,c):
    x = list(zip(a, b, c))
    return len(x) - len(set(x))