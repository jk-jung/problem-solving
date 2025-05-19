def min_min_max(arr):
    s, e = min(arr), max(arr)
    m = next((x for x in range(s + 1, e) if x not in arr))
    return [s, m, e]
