def highest_rank(v):
    return max(x for x in v if v.count(x) == max(v.count(y) for y in v))