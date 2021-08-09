class SnakesLadders():
    def __init__(self):
        self.p = 1
        self.end = False
        self.pos = [0, 0, 0]
        self.p2 = 0
        self.up = {2: 38, 7: 14, 8: 31, 15: 26, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 78: 98, 87: 94}
        self.down = {16: 6, 46: 25, 49: 11, 62: 19, 64: 60, 74: 53, 89: 68, 92: 88, 95: 75, 99: 80}

    def play(self, a, b):
        if self.end: return "Game over!"
        self.pos[self.p] += a + b
        if self.pos[self.p] > 100: self.pos[self.p] -= self.pos[self.p] % 100 * 2
        self.pos[self.p] = self.up.get(self.pos[self.p], self.pos[self.p])
        self.pos[self.p] = self.down.get(self.pos[self.p], self.pos[self.p])

        if self.pos[self.p] == 100:
            self.end = True
            r = f'Player {self.p} Wins!'
        else:
            r = f'Player {self.p} is on square {self.pos[self.p]}'
        if a != b: self.p = 3 - self.p
        return r
