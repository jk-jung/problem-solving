A = {
    'eggs': 1,
    'peanuts': 2,
    'shellfish': 4,
    'strawberries': 8,
    'tomatoes': 16,
    'chocolate': 32,
    'pollen': 64,
    'cats': 128
}

class Allergies(object):
    def __init__(self, score):
        assert isinstance(score, int)
        self.score = score

    def is_allergic_to(self, allergen):
        return (self.score & A[allergen]) > 0

    def allergies(self):
        return sorted([x for x, y in A.items() if (self.score & y) > 0])
