def shortest_to_char(s, c):
    if not s or not c or c not in s: return []
    return [min([abs(i - j) for j, y in enumerate(s) if y == c]) for i, x in enumerate(s)]
