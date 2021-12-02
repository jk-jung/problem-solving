# 012
# 345
# 678
m = [
    [1, 3],
    [0, 2, 4],
    [1, 5],
    [0, 4, 6],
    [1, 3, 5, 7],
    [2, 4, 8],
    [3, 7],
    [4, 6, 8],
    [5, 7]
]


def top(a):
    while max(a) > 3:
        b = a[::]
        for i in range(9):
            if a[i] > 3:
                b[i] -= 4
                for x in m[i]:
                    b[x] += 1
        a = b
    return a


class Sandpile:
    def __init__(self, x=""):
        self.v = [0 for _ in range(9)]
        for i, c in enumerate(x.replace('\n', '')):
            self.v[i] = int(c)
        self.v = top(self.v)

    def __str__(self):
        s = ''.join(str(x) for x in self.v)
        return s[:3] + '\n' + s[3:6] + '\n' + s[6:]

    def add(self, sp):
        a = self.v[::]
        for i in range(9):
            a[i] += sp.v[i]

        sp = Sandpile()
        sp.v = top(a)
        return sp
