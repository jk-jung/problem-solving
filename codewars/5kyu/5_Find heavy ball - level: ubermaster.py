def find_ball(sc, n, offset=0):
    if n == 1: return offset
    m =  (n + 2) // 3
    v = [list(range(offset, offset + n)[i * m: i * m + m]) for i in range(3)]
    r = {-1: 0, 1: 1, 0: 2}[sc.get_weight(v[0], v[1])]
    return find_ball(sc, len(v[r]), v[r][0])