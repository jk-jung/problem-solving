from fractions import Fraction as f
def add_fracs(*args):
    r = ''
    for x in args:
        r = str(f(r or '0') + f(x))
    return r
