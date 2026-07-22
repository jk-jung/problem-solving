HEX = set("0123456789ABCDEF")


def find_corrupted_byte(v):
    for i, x in enumerate(v):
        if len(x) != 2:
            return i
        if any(k not in HEX for k in x):
            return i
        try:
            int(x, 16)
        except:
            return i
    return -1
