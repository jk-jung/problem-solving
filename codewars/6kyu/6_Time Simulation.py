class SimTime:
    def __init__(self):
        self.t = 0
        self.r = 0
        self.s = 1

    def get(self):
        return self.r

    def update(self, x):
        if x < self.t: raise Exception("You shouldn't be able to travel back in time")
        self.r += (x - self.t) * self.s
        self.t = x

    def set_speed(self, x):
        self.s = x
