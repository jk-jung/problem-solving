def perfect_square(s):
    if s.replace('\n', '').replace('.', ''): return False
    s = s.split('\n')
    return all(len(x) == len(s) for x in s)
