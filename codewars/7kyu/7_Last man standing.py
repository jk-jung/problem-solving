def last_man_standing(n):
    t = list(range(n))
    while len(t) != 1:
        t = t[1::2][::-1]
    return t[0] + 1
