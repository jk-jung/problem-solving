class IllegalArgumentError(Exception):
    pass

class Graph:
    def __init__(self, v):
        self.V = v
        self.E = 0
        self.adj = [[] for _ in range(v)]
        if v < 0:
            raise IllegalArgumentError()

    def add_edge(self, v, w):
        if 0 <= v < self.V and 0 <= w < self.V:
            self.adj[v].append(w)
            self.adj[w].append(v)
            self.E += 1
        else: raise IllegalArgumentError ()
