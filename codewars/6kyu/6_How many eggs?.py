def egged(y, s):
    if y == 0: return "No chickens yet!"
    r, t = 0, 300
    for i in range(1, min(s, y) + 1):
        r += 1 * 3 * t
        t = int(t * 0.8)
    return r
