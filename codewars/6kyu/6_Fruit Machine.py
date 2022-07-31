from collections import Counter
score = {
    'Wild': (100, 10, 0),
    'Star': (90, 9, 18),
    'Bell': (80, 8, 16),
    'Shell': (70, 7, 14),
    'Seven': (60, 6, 12),
    'Cherry': (50, 5, 10),
    'Bar': (40, 4, 8),
    'King': (30, 3, 6),
    'Queen': (20, 2, 4),
    'Jack': (10, 1, 2),
}

def fruit(reels, spins):
    c = Counter([reels[i][x] for i, x in enumerate(spins)])
    if len(c) == 3: return 0
    s = score[c.most_common(1)[0][0]]
    if len(c) == 1: return s[0]
    return s[1] * (2 if c.most_common()[-1][0] == 'Wild' else 1)