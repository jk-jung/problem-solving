class HighScoreTable:

    def __init__(self, n):
        self.n = n
        self.scores = []
        # YOUR CODE HERE

    def update(self, x):
        self.scores.append(x)
        self.scores = sorted(self.scores)[::-1][:self.n]

    def reset(self):
        self.scores = []
