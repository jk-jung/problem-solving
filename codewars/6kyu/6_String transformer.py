def string_transformer(s):
    def f(t):
        return ''.join(x.lower() if x.isupper() else x.upper() for x in t)
    return ' '.join(reversed([f(x) for x in s.split(' ')]))