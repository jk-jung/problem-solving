class Nonogram:

    def __init__(self, clues):
        self.col = clues[0]
        self.row = clues[1]
        self.r = [[0 for _ in range(5)] for _ in range(5)]

    def solve(self):
        self.go(0, 0)
        return tuple(tuple(x for x in y) for y in self.r)

    def go(self, y=0, x=0):
        if x == 5:
            if not self.check_row(y): return False
            x, y = 0, y + 1
        if y == 5:
            for i in range(5):
                if not self.check_col(i): return False
            return True

        self.r[y][x] = 0
        if self.go(y, x +1): return True
        self.r[y][x] = 1
        if self.go(y, x +1): return True
        return False

    def check_row(self, y):
        t = [self.r[y][i] for i in range(5)]
        return self.row[y] == self.val(t)

    def check_col(self, x):
        t = [self.r[i][x] for i in range(5)]
        return self.col[x] == self.val(t)

    def val(self, t):
        r = [0]
        for i in range(5):
            if t[i] == 1: r[-1] += 1
            else: r.append(0)
        return tuple([x for x in r if x])

