class Dictionary:
    def __init__(self, words):
        self.words = words

    def find_most_similar(self, term):
        r = (len(term) + 1, '')
        for x in self.words:
            r = min(r, (self.f(x, term), x))

        return r[1]

    def f(self, a, b):
        n = len(a)
        m = len(b)
        d = [[999999 for _ in range(m + 1)] for _ in range(n + 1)]

        d[0][0] = 0
        for i in range(n + 1):
            for j in range(m + 1):
                if (i and j): d[i][j] = min(d[i][j], d[i - 1][j - 1] + (1 if a[i - 1] != b[j - 1] else 0))
                if (i): d[i][j] = min(d[i][j], d[i - 1][j] + 1)
                if (j): d[i][j] = min(d[i][j], d[i][j - 1] + 1)
        return d[n][m]
