def is_centered(v,n):
    if not v: return False
    if n == 0 and len(v) % 2 == 0: return True
    b = len(v) // 2
    a = (len(v) - 1) // 2

    s = v[a] if a == b else v[a] + v[b]
    while True:
        if s == n: return True
        a -= 1
        b += 1
        if a < 0 or b >= len(v): return False
        s += v[a]
        s += v[b]
        