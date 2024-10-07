def smallest_integer(a):
    a = sum(a, [])
    for i in range(len(a) + 10):
        if i not in a: return i