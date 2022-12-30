def get_root_property(d, v):
    for x, y in d.items():
        if isinstance(y, dict):
            r = get_root_property(y, v)
            if r is not None: return x
        elif v in y:
            return x
    return None
