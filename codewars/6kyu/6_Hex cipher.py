from preloaded import TEXT2HEX

class HexCipher:
    @classmethod
    def encode(cls, s, n):
        while n:
            n -= 1
            s = ''.join(TEXT2HEX[x] for x in s)
        return s

    @classmethod
    def decode(cls, s, n):
        rev = {v: k for k, v in TEXT2HEX.items()}
        while n:
            n -= 1
            s = ''.join(rev[s[i:i+2]] for i in range(0, len(s), 2))
        return s
