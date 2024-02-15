def digit_all (x):
    return 'Invalid input !' if not isinstance(x, str) else ''.join([y for y in x if y.isdigit()])
