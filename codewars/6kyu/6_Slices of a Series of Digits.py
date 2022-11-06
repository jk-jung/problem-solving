def series_slices(s, n):
    assert len(s) >= n
    r = [list(map(int, s[i:i + n])) for i in range(0, len(s) - n + 1)]
    return r