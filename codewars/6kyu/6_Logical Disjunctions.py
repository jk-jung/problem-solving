def disjunction(o, r):
    if not r: return any(o)
    else:
        r = '^'.join('1' if x else '0' for x in o)
        return True if eval(r) == 1 else False
