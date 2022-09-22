class Router(object):
    def __init__(self):
        self.v = {}

    def bind(self, x, y, f):
        self.v[(x, y)] = f

    def runRequest(self, x, y):
        if (x, y) in self.v:
            return self.v[(x, y)]()
        return 'Error 404: Not Found'
