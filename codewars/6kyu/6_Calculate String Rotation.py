def shifted_diff(a, b):
    for i in range(len(b)):
        if a == b: return i
        a = a[-1] + a[:-1]
    return -1
