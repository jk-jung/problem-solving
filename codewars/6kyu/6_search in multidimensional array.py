def locate(seq, value):
    if isinstance(seq, list) or isinstance(seq, tuple):
        return any(locate(x, value) for x in seq)
    return seq == value
