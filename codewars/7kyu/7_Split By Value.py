def split_by_value(k, t):
    return [x for x in t if x < k] + [x for x in t if x >= k]
