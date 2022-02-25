class VigenereAutokeyCipher:
    def __init__(self, key, abc):
        self.key = key
        self.abc = abc

    def encode(self, text):
        r = ''
        pos = 0
        key = self.key + ''.join(x for x in text if x in self.abc) * len(text)
        for x in text:
            i = self.abc.find(x)
            if i != -1:
                j = self.abc.find(key[pos])
                pos += 1
                r += self.abc[(i + j) % len(self.abc)]
            else:
                r += x
        return r

    def decode(self, text):
        r = ''
        pos = 0
        key = self.key
        for x in text:
            i = self.abc.find(x)
            if i != -1:
                j = self.abc.find(key[pos])
                pos += 1
                r += self.abc[(i - j + len(self.abc)) % len(self.abc)]
                key += r[-1]
            else:
                r += x
        return r