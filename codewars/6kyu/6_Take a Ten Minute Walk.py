def is_valid_walk(w):
    return len(w) == 10 and w.count('n') == w.count('s') and w.count('w') == w.count('e')
