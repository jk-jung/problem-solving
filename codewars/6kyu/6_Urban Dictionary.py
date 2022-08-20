class WordDictionary:
    def __init__(self):
        self.data = []

    def add_word(self, word):
        self.data.append(word)

    def search(self, x):
        for y in self.data:
            if len(x) == len(y) and all(a == '.' or a == b for a, b in zip(x, y)):
                return True
        return False
