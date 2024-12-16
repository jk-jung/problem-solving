def solve(st):
    for x, y in zip(st, st[::-1]):
        if abs(ord(x) - ord(y)) not in (0, 2):
            return False
    return True