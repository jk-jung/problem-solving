class Player(RockPaperScissorsPlayer):
    def __init__(self):
        self.o = ''
        self.r = 0
        self.s = ''

    def get_name(self):
        return "MyPlayer"

    def get_shape(self):
        if self.o == 'Jonathan Hughes': return 'SRP'[self.r % 3]
        if self.o == 'Vitraj Bachchan': return 'R'
        if self.o == 'Bin Jinhao':return 'RPRSPS'[self.r % 6]
        if self.o == 'Sven Johanson': return 'R'
        t = "PRS"[random.randint(0, 2)]
        return 'P'

    def set_new_match(self, opponentName):
        self.o = opponentName
        self.r = 0

    def set_opponent_shape(self, shape):
        self.s = shape
        self.r += 1
