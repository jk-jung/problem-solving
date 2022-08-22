def ranks(a):
    return [sum(1 for x in a if x > y) + 1 for y in a]