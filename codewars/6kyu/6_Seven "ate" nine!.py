def hungry_seven(r):
    for i in range(2, len(r)):
        while i >= 2 and r[i-2] == 7 and r[i-1] == 8 and r[i] == 9:
            r[i-2], r[i-1], r[i] = 8, 9, 7
            i -= 1
    return r
