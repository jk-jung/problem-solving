from math import ceil

class Potion:
    def __init__(self, c, v):
        self.color = self.c = tuple(map(ceil, c))
        self.volume = self.v = v

    def mix(self, o):
        t = self.v + o.v
        c = tuple((x * self.v + y * o.v) / t for x, y in zip(self.c, o.c))
        return Potion(c, t)
