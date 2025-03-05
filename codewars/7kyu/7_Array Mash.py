def array_mash(a, b):
    return sum(map(list, zip(a, b)), [])
