def generate_sequence(s, e):
    if e - s == 4: return [s + 1, s + 3, s, s + 2]
    return list(range(s, e, 2)) + list(range(s + 1, e, 2))
