values = {
    'queen': 9,
    'rook': 5,
    'bishop': 3,
    'knight': 3,
    'pawn': 1,
}

def pieces_value(v, s):
    r = 0
    for a in v:
        for x in a:
            if x[0] == s[0]:
                for c, d in values.items():
                    if c in x:r += d

    return r