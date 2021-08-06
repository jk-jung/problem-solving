class DynamicConnectivity(object):
    # class takes the number of objects n as input,
    # and initializes a data structure with objects numbered from
    # 0 to N-1
    def __init__(self, n):
        self.p = list(range(n))

    # union connects point p with point q
    def union(self, p, q):
        self.p[self.f(p)] = self.p[self.f(q)]

    # connected checks if point p is connected to point q and returns a boolean
    def connected(self, p, q):
        return self.f(p) == self.f(q)

    def f(self, x):
        t = []
        while x != self.p[x]:
            t.append(x)
            x = self.p[x]
        for y in t: self.p[y] = x
        return x
