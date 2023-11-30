def gas_station(v, a, b):
    r = (1 << 30, None)
    b /= 100
    for x, y in v.items():
        d = y['distance']
        p = y['price']
        if a >= d * b:
            t = (60 - (a - d * b * 2)) * p
            r = min(r, (t, x))
    return r[1]