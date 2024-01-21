def switch_lights(a):
    c = 0
    r = []
    for x in a[::-1]:
        c = (c + x) % 2
        r.append(x ^ c)
    return r[::-1]
