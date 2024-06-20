def cube_odd(v):
    try:
        if not all(type(x) == type(0) for x in v):
            return
        v = [x for x in v if x % 2]
        return sum(x**3 for x in v)
    except:
        pass
