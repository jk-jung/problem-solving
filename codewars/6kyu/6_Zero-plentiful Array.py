def zero_plentiful(v):
    v.append(1)
    z, r = 0, 0
    for x in v:
        if x == 0:
            z += 1
        else:
            if z and z < 4:
                return 0
            if z: r += 1
            z = 0
    return r