class Pong:
    def __init__(self, max_score):
        self.max_score = max_score;
        self.turn = 2
        self.over = False
        self.score = [0, 0, 0]

    def play(self, a, b):
        self.turn = 3 - self.turn
        if self.over: return "Game Over!"
        if b - 3 <= a <= b + 3: return f"Player {self.turn} has hit the ball!"
        else:
            self.score[self.turn] += 1
            if self.score[self.turn] == self.max_score:
                self.over = True
                return f"Player {3 - self.turn} has won the game!"
            return f"Player {self.turn} has missed the ball!"
