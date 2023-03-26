def snakes_and_ladders(b, d):
    r = 0
    for x in d:
        if r + x < len(b): r += x
        if b[r]: r += b[r]
        if r == len(b) - 1: return len(b) - 1
    return r
