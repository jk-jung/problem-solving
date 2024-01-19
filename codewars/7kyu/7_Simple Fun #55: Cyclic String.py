def cyclic_string(s):
    for i in range(1, len(s) + 1):
        if s in s[:i] * 100:return i
