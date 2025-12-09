class Cube(object):
    def __init__(self, n=0):
        self.n = abs(n)

    def get_side(self):
        return self.n

    def set_side(self, new_side):
        self.n = abs(new_side)
