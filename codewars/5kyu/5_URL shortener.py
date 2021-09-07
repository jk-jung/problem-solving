class Url_shortener:
    def __init__(self):
        self.db = {}
        self.rev = {}
        self.cnt = 0

    def shorten(self, long_url):
        if long_url not in self.db:
            u = self.generate()
            self.db[long_url] = u
            self.rev[u] = long_url
        return self.db[long_url]


    def redirect(self, u):
        return self.rev[u]

    def generate(self):
        r = ''
        x = self.cnt
        self.cnt += 1
        while True:
            r += chr(ord('a') + x % 26)
            x //= 26
            if x <= 0: break
            x -= 1
        return 'short.ly/' + r