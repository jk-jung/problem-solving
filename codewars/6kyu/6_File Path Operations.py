class FileMaster():
    def __init__(self, filepath):
        self.s = filepath

    def extension(self):
        return self.s.split('.')[-1]

    def filename(self):
        return self.s.split('/')[-1].split('.')[0]

    def dirpath(self):
        return self.s.rsplit('/', 1)[0] + '/'
