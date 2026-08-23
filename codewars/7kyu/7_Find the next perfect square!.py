def find_next_square(s):
    t = round(s ** .5)
    if t ** 2 == s:
        return (t + 1) ** 2
    return -1
