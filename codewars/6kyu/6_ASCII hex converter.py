import binascii

class Converter():
    @staticmethod
    def to_ascii(h):
        return binascii.unhexlify(h).decode()
    @staticmethod
    def to_hex(s):
        return binascii.hexlify(s.encode()).decode()
