def find_secret_number(s, e, f):
    while s <= e:
        m = (s + e) // 2
        r = f.guess_number(m)

        if r == 'Correct': return m
        elif r == 'Smaller': e = m - 1
        else: s = m + 1
