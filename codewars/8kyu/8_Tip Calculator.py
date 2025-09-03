from math import ceil


def calculate_tip(a, b):
    b = b.lower()
    if b == "terrible":
        return 0
    if b == "poor":
        return ceil(a * 0.05)
    if b == "good":
        return ceil(a * 0.1)
    if b == "great":
        return ceil(a * 0.15)
    if b == "excellent":
        return ceil(a * 0.2)
    return "Rating not recognised"
