import numpy as np
def stats_disc_distr(v):
    a, b = False, False
    if abs(sum(x[1] for x in v) - 1) > 1e-9: a = True
    if not all(isinstance(x[0], int) for x in v): b = True

    if a and b: return "It's not a valid distribution and furthermore, one or more variable value are not integers"
    if a: return "It's not a valid distribution"
    if b: return 'All the variable values should be integers'

    m = sum(x[0] * x[1] for x in v)
    r = sum((m - x[0]) ** 2 * x[1] for x in v)
    return [m, r, r ** .5]