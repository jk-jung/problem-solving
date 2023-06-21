def string_constructing(a, s):
    r = 0
    while s:
        r += 1 + len(a)
        for x in a:
            if x == s[0]:
                r -= 1
                if not (s := s[1:]): return r

