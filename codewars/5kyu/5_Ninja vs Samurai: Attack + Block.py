Position = {'high': 'h', 'low': 'l'}  #don't change this!

class Warrior():
    def __init__(self, name):
        # each warrior should be created with a name and 100 health points
        self.name = name
        self.health = 100
        # default guard is "", that is unguarded
        self.block = ""
        self.deceased = False
        self.zombie = False

    def attack(self, enemy, position):
        if enemy.block == position:
            damage = 0
        else:
            damage = 10 if position == Position['high'] else 5
            if enemy.block == "": damage += 5
        enemy.set_health(enemy.health - damage)

    def set_health(self, new_health):
        self.health = max(0, new_health)
        if self.deceased: self.zombie = True
        if self.health == 0: self.deceased = True
