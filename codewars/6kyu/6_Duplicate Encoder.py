def duplicate_encode(w):
    w = w.lower()
    return ''.join('(' if w.count(x) == 1 else ')' for x in w)
