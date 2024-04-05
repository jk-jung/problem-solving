def reject(seq, predicate):
    return [x for x in seq if not predicate(x)]
