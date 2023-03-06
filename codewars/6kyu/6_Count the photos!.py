def count_photos(road):
    r, s, e = 0, 0, 0
    for x in road:
        if x == '>': s+= 1
        if x == '.': r += s
    for x in road[::-1]:
        if x == '<': e += 1
        if x == '.': r += e
    return r
