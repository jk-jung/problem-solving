class Grid():
    def __init__(self, w, h):
        self.v = [['0'] * w for _ in range(h)]
        self.grid = str(self)

    def plot_point(self, x, y):
        self.v[y-1][x-1] = 'X'
        self.grid = str(self)

    def __repr__(self):
        return '\n'.join(''.join(x) for x in self.v)
