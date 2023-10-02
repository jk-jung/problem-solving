def flat_rotors(lines_before, lines_after):
    r = []
    n = len(ALPHABET)
    for a, b in zip(lines_before, lines_after):
        s = 0
        t = []
        for x, y in zip(a, b):
            d = ALPHABET.index(y) - ALPHABET.index(x)
            if d < 0: d += n
            t.append((d - s + n) % n)
            s = d % n
        r.append(t)
    return r
