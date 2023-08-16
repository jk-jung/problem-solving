def product_array(v):
    r = 1
    for x in v:r *= x
    return [r // x for x in v]
