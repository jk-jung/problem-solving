def partition(a, b):
    return [x for x in a if b(x)], [x for x in a if not b(x)]