import re
class VersionManager:
    def __init__(self, v=None):
        if not v: v = '0.0.1'
        self.a, self.b, self.c, *d = (v + '.0.0.0.0.0.0.0.0').split('.')
        try:
            self.a = int(self.a)
            self.b = int(self.b)
            self.c = int(self.c)
        except:
            raise Exception('Error occured while parsing version!')
        self.v = [self.release()]
        print(self.a, self.b, self.c)

    def release(self):
        return f'{self.a}.{self.b}.{self.c}'

    def major(self):
        self.a += 1
        self.b = 0
        self.c = 0
        self.v.append(self.release())
        return self

    def minor(self):
        self.b += 1
        self.c = 0
        self.v.append(self.release())
        return self

    def patch(self):
        self.c += 1
        self.v.append(self.release())
        return self

    def rollback(self):
        if len(self.v) == 1: raise Exception('Cannot rollback!')
        self.v.pop()
        self.a, self.b, self.c = map(int, self.v[-1].split('.'))
        return self
