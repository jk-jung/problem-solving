def destroyer(input_sets):
    r = []
    for i in range(0, 26):
        x = chr(ord('a') + i)
        bad = any(x in s for s in input_sets)
        r.append('_' if bad else x)
    return ' '.join(r)
