from string import ascii_uppercase as a

class CaesarCipher(object):
    def __init__(self, shift):
        self.sh = shift

    def encode(self, st):
        return ''.join([a[(ord(x) - ord('A') + self.sh) % 26] if x in a else x for x in st.upper()])


    def decode(self, st):
        return ''.join([a[(ord(x) - ord('A') - self.sh) % 26] if x in a else x for x in st.upper()])