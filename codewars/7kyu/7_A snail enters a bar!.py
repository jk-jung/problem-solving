def can_snail_reach_end(x, y, z):
    if y <= z:
        return False
    return x / (y - z) <= 365 * 24 * 60