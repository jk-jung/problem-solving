def to_seconds(t):
    a, b, c = t.split(':')
    if len(a) != 2 or not(0 <= int(a) < 100): return
    if len(b) != 2 or not(0 <= int(b) < 60): return
    if len(c) != 2 or not(0 <= int(c) < 60): return
    return int(a) * 3600 + int(b) * 60 + int(c)
