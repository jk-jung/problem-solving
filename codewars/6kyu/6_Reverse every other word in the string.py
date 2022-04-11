def reverse_alternate(s):
    def f(x):
        return ''.join(reversed(x))
    s = [x for x in s.split(' ') if x]
    return ' '.join(f(x) if i % 2 else x for i, x in enumerate(s))
