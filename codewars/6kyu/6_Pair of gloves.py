def number_of_pairs(v):
    return sum(v.count(x) // 2 for x in set(v))
