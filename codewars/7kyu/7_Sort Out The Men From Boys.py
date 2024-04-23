def men_from_boys(a):
    b = {x for x in a if x % 2}
    a = {x for x in a if x % 2 == 0}
    return sorted(a) + sorted(b)[::-1]
