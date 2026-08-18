def is_valid(x):
    if 1 in x and 2 in x:
        return False
    if 3 in x and 4 in x:
        return False
    if 7 not in x and 8 not in x:
        return False
    if 5 in x and 6 not in x:
        return False
    if 6 in x and 5 not in x:
        return False
    return True
