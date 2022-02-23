class SecureList():
    def __init__(self, v):
        self.v = v[:]

    def __getitem__(self, i):
        return self.v.pop(i)

    def __str__(self):
        r = str(self.v)
        self.v = []
        return r

    def __repr__(self):
        return self.__str__()

    def __len__(self):
        return len(self.v)
