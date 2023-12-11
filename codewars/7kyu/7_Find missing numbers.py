def find_missing_numbers(v):
    if not v: return v
    return [i for i in range(min(v), max(v)) if i not in v]
