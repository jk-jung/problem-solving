class Warrior:
    ranks = ["Pushover", "Novice", "Fighter", "Warrior",
             "Veteran", "Sage", "Elite", "Conqueror",
             "Champion", "Master", "Greatest"]
    max_exp = 10000

    def __init__(self):
        self.level = 1
        self.experience = 100
        self.rank = Warrior.ranks[0]
        self.rank_level = 0
        self.achievements = []

    def battle(self, level):
        if level < 1 or level > 100: return 'Invalid level'
        diff = level - self.level

        if self.rank_level < level // 10 and diff >= 5: return "You've been defeated"

        if diff <= 0:
            self._add_exp(max(0, 10 + diff * 5))
        else:
            self._add_exp(20 * diff * diff)

        if diff <= -2:
            return 'Easy fight'
        elif diff <= 0:
            return 'A good fight'
        return 'An intense fight'

    def training(self, args):
        desc, exp, min_level = args
        if self.level < min_level: return 'Not strong enough'

        self._add_exp(exp)
        self.achievements.append(desc)
        return desc

    def _add_exp(self, point):
        self.experience = min(self.experience + point, Warrior.max_exp)
        self.level = self.experience // 100
        self.rank_level = self.level // 10
        self.rank = Warrior.ranks[self.rank_level]
