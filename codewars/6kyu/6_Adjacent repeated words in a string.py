def count_adjacent_pairs(s):
    last, r, t = 1, 0, 0
    for x in s.lower().split(' '):
        if x == last:
            if t == 0:
                r += 1
            t = 1
        else:
            t = 0
        last = x
    return r
