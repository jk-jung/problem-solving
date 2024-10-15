def per(n):
    if n < 10: return []
    x = 1
    for y in str(n): x *= int(y)
    return [x] + per(x)