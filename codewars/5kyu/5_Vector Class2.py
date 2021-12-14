class Vector:
    def __init__(self, a, b=None, c=None):
        if isinstance(a, list) or isinstance(a, tuple): self.v = a
        else: self.v = [a,b,c]
        self.x = self.v[0]
        self.y = self.v[1]
        self.z = self.v[2]
        self.magnitude = sum(x*x for x in self.v) ** .5

    def __eq__(self, t):
        return all(a == b for a, b in zip(self.v, t.v))

    def __str__(self):
        return f"<{', '.join(str(x) for x in self.v)}>"

    def __add__(self, t):
        return Vector([a + b for a, b in zip(self.v, t.v)])

    def __sub__(self, t):
        return Vector([a - b for a, b in zip(self.v, t.v)])

    def to_tuple(self):
        return tuple(self.v)

    def cross(self, t):
        a, b = self.v, t.v
        return Vector(
            a[1] * b[2] - a[2] * b[1],
            a[2] * b[0] - a[0] * b[2],
            a[0] * b[1] - a[1] * b[0],
            )

    def dot(self, t):
        return sum(a * b for a, b in zip(self.v, t.v))