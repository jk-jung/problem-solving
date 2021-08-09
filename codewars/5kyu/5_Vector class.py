class Vector:
    def __init__(self, v):
        self.v = v or []

    def add(self, y):
        assert len(y.v) == len(self.v)
        return Vector([x+y for x,y in zip(self.v, y.v)])

    def subtract(self, y):
        assert len(y.v) == len(self.v)
        return Vector([x-y for x,y in zip(self.v, y.v)])

    def dot(self, y):
        assert len(y.v) == len(self.v)
        return sum(x*y for x,y in zip(self.v, y.v))

    def norm(self):
        return sum(x*x for x in self.v) ** .5

    def equals(self, y):
        return y.v == self.v

    def __str__(self):
        return '(' + ','.join(str(x) for x in self.v) + ')'
