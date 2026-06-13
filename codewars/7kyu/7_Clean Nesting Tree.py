def is_cleanly_nested(a):
    if any(len(x) == 0 for x in a):
        return all(len(x) == 0 for x in a)
    else:
        return all(map(is_cleanly_nested, a))
