def house_numbers_sum(v):
    r = 0
    for x in v:
        r += x
        if x == 0:break
    return r
