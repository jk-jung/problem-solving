def alphanumeric(s):
    if len(s) == 0: return False
    for x in s:
        if x not in '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ':
            return False
    return True
