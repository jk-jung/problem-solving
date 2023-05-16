def to_and_from(a, b, t):
    x, y = divmod(t, abs(b - a))
    if x % 2 == 0: return a + y if a < b else a - y
    return b - y if a < b else b + y
