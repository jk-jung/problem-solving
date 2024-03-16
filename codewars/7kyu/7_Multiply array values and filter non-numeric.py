def multiply_and_filter(a, b):
    return [x * b for x in a if x is not False and x is not True and (isinstance(x, int) or isinstance(x, float))]
