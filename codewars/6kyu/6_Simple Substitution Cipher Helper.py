class Cipher(object):
    def __init__(self, map1, map2):
        self.a = map1
        self.b = map2

    def encode(self, s):
        return ''.join([self.b[self.a.find(x)] if self.a.find(x) != -1 else x for x in s])

    def decode(self, s):
        return ''.join([self.a[self.b.find(x)] if self.b.find(x) != -1 else x for x in s])
