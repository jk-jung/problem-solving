class Random():
    def __init__(self, seed):
        self._seed = seed
        self.cnt = 0

    @property
    def seed(self):
        return self._seed

    @seed.setter
    def seed(self, seed):
        self._seed = seed
        self.cnt = 0

    def random(self):
        self.cnt = (self.cnt * self.seed + self.seed) % 1234567
        return self.cnt / 1234567

    def randint(self, start, end):
        return int(self.random() * (end - start) + start)
