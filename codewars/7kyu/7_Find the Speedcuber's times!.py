def cube_times(s):
    s.sort()
    return round(sum(s[1:-1]) / 3, 2), s[0]
