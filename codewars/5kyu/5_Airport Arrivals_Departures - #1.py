def flap_display(lines, rotors):
    r = []
    for a, b in zip(lines, rotors):
        t = ''
        s = 0
        for x, y in zip(a, b):
            s += y
            t += ALPHABET[(ALPHABET.index(x) + s) % len(ALPHABET)]
        r.append(t)
    return r
