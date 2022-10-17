def calculate_optimal_fare(d, t, v1, r, v2):
    v1 /= 60
    v2 /= 60
    if max(v1, v2) * t < d:
        return "Won't make it!"
    if v1 <= v2: return "0.00"
    x = (d - v2 * t) / (v1 - v2) * v1 * r
    if x < 0: return "0.00"
    return '%0.2f' % x
