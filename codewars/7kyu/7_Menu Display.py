class Menu:
    def __init__(self, v):
        self.i = 0
        self.v = []
        for i in range(len(v)):
            self.v.append(v[:])
            self.v[-1][i] = [self.v[-1][i]]

    def to_the_right(self):
        self.i = (self.i + 1) % len(self.v)

    def to_the_left(self):
        self.i = (self.i - 1 + len(self.v)) % len(self.v)

    def display(self):
        return str(self.v[self.i])
