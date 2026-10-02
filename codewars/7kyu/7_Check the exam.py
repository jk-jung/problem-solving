def check_exam(a, b):
    return max(0, sum(0 if y == '' else (4 if x == y else -1) for x, y in zip(a, b)))
