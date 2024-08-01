def candies(v):
    if len(v) < 2: return -1
    return sum(max(v) - x for x in v)