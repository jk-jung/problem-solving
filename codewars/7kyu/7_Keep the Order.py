def keep_order(ary, val):
    for i, x in enumerate(ary):
        if x >= val:
            return i
    return len(ary)
