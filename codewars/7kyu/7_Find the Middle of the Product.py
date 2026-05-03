def find_middle(s):
    if not isinstance(s, str):
        return -1
    s = [int(x) for x in s if x.isdigit()]
    if not s:
        return -1
    r = 1
    for x in s:
        r *= x
    r = str(r)
    n = len(r)
    return int(r[(n - 1) // 2 : n // 2 + 1])
