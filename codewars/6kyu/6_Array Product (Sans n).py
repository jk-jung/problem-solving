def product_sans_n(v):
    r, r2, z = 1, 1, 0
    for x in v:
        if not x: z += 1
        else: r2 *= x
        r *= x

    return [r // x if x else (r2 if z == 1 else 0) for x in v]
