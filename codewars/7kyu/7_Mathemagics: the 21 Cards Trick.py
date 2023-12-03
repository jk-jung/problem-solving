# The audience member will always select one of these options
DECK = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21]

def guess_the_card(a):
    r = {
        1:  [0, 0, 0],
        2:  [0, 1, 0],
        3:  [0, 2, 0],
        4:  [0, 0, 1],
        5:  [0, 1, 1],
        6:  [0, 2, 1],
        7:  [0, 0, 2],
        8:  [1, 1, 1],
        9:  [1, 2, 1],
        10: [1, 0, 1],
        11: [1, 1, 2],
        12: [1, 2, 2],
        13: [1, 0, 2],
        14: [1, 1, 0],
        15: [2, 2, 2],
        16: [2, 0, 2],
        17: [2, 1, 2],
        18: [2, 2, 0],
        19: [2, 0, 0],
        20: [2, 1, 0],
        21: [2, 2, 1],
    }
    t = []
    def build(i):
        vv = [[], [], []]
        for k, v in r.items():
            vv[v[i]].append(k)
        return vv

    t = [a.get_input(build(i)) for i in range(3)]
    for k, v in r.items():
        if t == v: return k
