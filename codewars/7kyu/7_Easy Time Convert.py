def time_convert(n):
    n = max(0, n)
    return '%02d:%02d' % (n // 60, n % 60)
