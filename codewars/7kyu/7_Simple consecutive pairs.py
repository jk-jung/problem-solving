def pairs(v):
    return sum([abs(v[i] - v[i:i+2][-1]) == 1 for i in range(0, len(v), 2)])
