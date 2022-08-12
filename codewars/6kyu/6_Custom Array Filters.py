class list(list):
    def __init__(self, *args):
        super().__init__([x for x in args[0] if isinstance(x, int)])

    def even(self):
        return [x for x in self if x % 2 == 0]

    def odd(self):
        return [x for x in self if x % 2 == 1]

    def under(self, y):
        return [x for x in self if x < y]

    def over(self, y):
        return [x for x in self if x > y]

    def in_range(self, s, e):
        return [x for x in self if s <= x and x <= e]