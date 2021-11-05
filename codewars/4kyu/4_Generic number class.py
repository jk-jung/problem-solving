def create_number_class(v):
    def __init__(self, x):
        self.x = x
        self.r = 0

        for y in x:
            self.r = self.r * len(v) + v.index(y)

    def to_alpha(self, x):
        r = []
        while x:
            r.append(v[x % len(v)])
            x //= len(v)
        return ''.join(reversed(r)) or v[0]

    def __add__(self, x):
        return self.__class__(self.to_alpha(self.r + x.r))

    def __sub__(self, x):
        return self.__class__(self.to_alpha(self.r - x.r))

    def __mul__(self, x):
        return self.__class__(self.to_alpha(self.r * x.r))

    def __floordiv__(self, x):
        return self.__class__(self.to_alpha(self.r // x.r))

    def __str__(self):
        return self.x

    def convert_to(self, cls):
        return cls(cls('').to_alpha(self.r))

    funcs = {
        'v': v,
        '__init__': __init__,
        '__add__': __add__,
        '__sub__': __sub__,
        '__mul__': __mul__,
        '__floordiv__': __floordiv__,
        '__str__': __str__,
        'convert_to': convert_to,
        'to_alpha': to_alpha,
    }
    return type(v, (), funcs)

