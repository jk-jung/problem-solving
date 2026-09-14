def repeats(a):
    return sum([x for x in a if a.count(x) == 1])
