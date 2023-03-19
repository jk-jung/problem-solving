def roof_fix(f, r):
    for x, y in zip(f, r):
        if y in '\/' and x != ' ': return False
    return True