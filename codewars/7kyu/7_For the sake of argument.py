def numbers(*v):
    return all(isinstance(x, (int, float)) and not isinstance(x, bool) for x in v)
