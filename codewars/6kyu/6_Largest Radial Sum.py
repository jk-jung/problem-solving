def largest_radial_sum(v, d):
    d = len(v) // d
    return max(sum(x for x in v[i:len(v):d]) for i in range(d))
