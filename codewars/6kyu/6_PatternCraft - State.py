class SiegeState:
    def __init__(self):
        self.can_move = False
        self.damage = 20


class TankState:
    def __init__(self):
        self.can_move = True
        self.damage = 5


class Tank:
    def __init__(self):
        self.state = TankState()

    def can_move(self):
        return self.state.can_move

    def damage(self):
        return self.state.damage
