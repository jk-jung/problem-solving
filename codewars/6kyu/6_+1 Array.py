def up_array(v):
    if not v or any(x < 0 or x > 9 for x in v): return
    return list(map(int, str(int(''.join(str(x) for x in v)) + 1)))