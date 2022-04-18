def ip_to_int32(x):
    r = 0
    for x in x.split('.'):
        r = r * 256 + int(x)
    return r