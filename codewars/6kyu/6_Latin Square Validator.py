def verify_latin_square(a, n):
    s = {i + 1 for i in range(n)}
    if any(len(x) != n for x in a) or len(a) != n:
        t = {len(x) for x in a}
        if len(t) == 1 and len(a[0]) == len(a): return 'Array is wrong size'
        return "Array not square"
    for i, x in enumerate(a):
        for j, k in enumerate(x):
            cnt = x.count(k)
            if cnt >= 2: return f"{k} occurs more than once in row {i + 1}"
        for j, k in enumerate(x):
            if k not in s: return f"{k} at {i + 1},{j + 1} is not between 1 and {n}"
    for i, x in enumerate(zip(*a)):
        for j, k in enumerate(x):
            cnt = x.count(k)
            if cnt >= 2: return f"{k} occurs more than once in column {i + 1}"
    return  f"Valid latin square of size {n}"
