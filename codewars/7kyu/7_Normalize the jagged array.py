def normalize(arr, fill_value=None):
    if not arr: return arr
    m = max(map(len, arr))
    return [(x + [fill_value] * m)[:m] for x in arr]
