from collections import Counter

class Jar():
    def __init__(self):
        self.c = Counter()

    def add (self, amount, kind):
        self.c[kind] += amount

    def pour_out (self, amount):
        p = 1 - amount / self.get_total_amount()
        for k in self.c:
            self.c[k] *= p

    def get_total_amount(self):
        return sum(self.c.values())

    def get_concentration(self, kind):
        if self.get_total_amount() == 0: return 0
        return self.c[kind] / self.get_total_amount()
