def solve(a, b):
    if '*' in a:
        x, y = a.split('*')
        return len(x) + len(y) <= len(b) and b.startswith(x) and b.endswith(y)
    return a == b
