def to_bits(s):
    s = set(map(int, s.split('\n')))
    return [1 if i in s else 0 for i in range(5000)]
