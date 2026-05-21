from math import gcd
def calculate_ratio(w, h):
    assert w * h > 0
    g = gcd(w, h)
    return f"{w//g}:{h//g}"