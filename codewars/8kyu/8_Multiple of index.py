def multiple_of_index(a):
    return [x for i, x in enumerate(a) if (i and x % i == 0) or x == 0]
