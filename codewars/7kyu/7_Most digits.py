def find_longest(x):
    return sorted(x, key=lambda x: -len(str(x)))[0]
