class SelfClosing(object):

    def __init__(self, cookie_jar):
        self.x = cookie_jar

    def __enter__(self):
        self.x.open_jar()
        return self.x

    def __exit__(self, *args):
        self.x.close_jar()
