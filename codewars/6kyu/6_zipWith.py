def zip_with(f,a1,a2):
    return [f(*a) for a in zip(a1, a2)]
