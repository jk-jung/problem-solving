def period_is_late(a, b, c):
    return (b - a).total_seconds() > c * 24 * 3600
