class Dictionary():
    def __init__(self):
        self.t = {}

    def newentry(self, word, definition):
        self.t[word] = definition

    def look(self, key):
        return self.t.get(key, f"Can't find entry for {key}")
