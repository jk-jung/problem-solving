from itertools import combinations
def find_number(v):
    if len(v) <= 1:
        if v[0] > 9:
            return 9 * 10 + v[0] - 9
        return v[0]
    m = int((len(v) * 2) ** .5) + 1
    x = (v[0] + v[1] - v[m - 1]) // 2
    r = x
    for i in range(0, m - 1):
        r = r * 10 + v[i] - x
    return r
