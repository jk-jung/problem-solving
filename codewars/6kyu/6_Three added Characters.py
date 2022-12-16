def added_char(s1, s2):
    for x in s2:
        if s1.count(x) != s2.count(x): return x
