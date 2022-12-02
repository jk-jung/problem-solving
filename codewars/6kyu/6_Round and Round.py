from decimal import *
getcontext().prec = 100000
getcontext().rounding = ROUND_HALF_UP

def round_by_2_decimal_places(n):
    return round(n,2)
