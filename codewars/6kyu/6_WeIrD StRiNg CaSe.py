def to_weird_case(s):
    def f(x):
        return ''.join(i.lower() if j % 2 else i.upper() for j, i in enumerate(x))
    return ' '.join(f(x) for x in s.split(' '))
