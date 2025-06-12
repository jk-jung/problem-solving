def flip(a, d):
    d.sort()
    return d if a == 'R' else d[::-1]