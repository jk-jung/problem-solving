def find_in_array(seq, predicate):
    for i, x in enumerate(seq):
        if predicate(x, i):
            return i
    return -1
