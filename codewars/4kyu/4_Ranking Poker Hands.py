from collections import Counter


class PokerHand(object):
    RESULT = ["Loss", "Tie", "Win"]

    def __init__(self, hand):
        int_map = {'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14}
        self.cards = [(int(int_map.get(x[0], x[0])), x[1]) for x in hand.split(' ')]
        self.cards.sort()
        c = Counter(x[0] for x in self.cards)
        self.t1 = c.most_common()[0]
        self.t2 = c.most_common()[1]
        self.tb = list(reversed(sorted([(v, k) for k, v in c.items()])))
        self.rank = self.get_rank()

    def compare_with(self, other):
        if self.rank == other.rank:
            if self.tb == other.tb: return 'Tie'
            return 'Win' if self.tb > other.tb else 'Loss'
        return 'Win' if self.rank < other.rank else 'Loss'

    def get_rank(self):
        order = [
            self.is_straight_flush,
            self.is_4cards,
            self.is_full_house,
            self.is_flush,
            self.is_straight,
            self.is_three_cards,
            self.is_two_pairs,
            self.is_pair,
            self.is_heightcard
        ]
        for i, x in enumerate(order):
            if x(): return i

    def is_straight_flush(self):
        return self.is_straight() and self.is_flush()

    def is_straight(self):
        t = set(self.cards[i + 1][0] - self.cards[i][0] for i in range(4))
        return len(t) == 1 and self.cards[1][0] - self.cards[0][0] == 1

    def is_flush(self):
        return len(set(x[1] for x in self.cards)) == 1

    def is_4cards(self):
        return self.t1[1] == 4

    def is_full_house(self):
        return self.t1[1] == 3 and self.t2[1] == 2

    def is_three_cards(self):
        return self.t1[1] == 3

    def is_two_pairs(self):
        return self.t1[1] == 2 and self.t2[1] == 2

    def is_pair(self):
        return self.t1[1] == 2

    def is_heightcard(self):
        return True
