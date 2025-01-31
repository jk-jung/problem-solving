def max_sum_between_two_negatives(a):
    r = -1
    f = 0
    s = 0
    for x in a:
        if x < 0:
            if f > 0:
                r = max(r, s)
            f += 1
            s = 0
        if f > 0 and x > 0:
            s += x
    return r
