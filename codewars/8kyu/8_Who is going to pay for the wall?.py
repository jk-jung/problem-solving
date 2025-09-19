def who_is_paying(n):
    return [n] if len(n) < 3 else [n, n[:2]]
