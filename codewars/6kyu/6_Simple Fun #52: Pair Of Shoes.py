def pair_of_shoes(v):
    a = sorted([x[1] for x in v if x[0] == 0])
    b = sorted([x[1] for x in v if x[0] == 1])
    return a == b