def find_lowest_int(k):
    r = 1
    while True:
        if sorted(str(k * r)) == sorted(str((k * r + r))):
            return r
        r += 1
