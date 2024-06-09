def apple_boxes(k):
    r, t = 0, 1
    for i in range(k + 1):
        r += i * i * t
        t = -t
    return r
