def data_reverse(v):
    r = []
    for i in range(0, len(v), 8):
        for x in v[i:i+8][::-1]:
            r = [x] + r
    return r