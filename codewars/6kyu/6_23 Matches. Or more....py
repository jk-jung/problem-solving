from collections import namedtuple

Bot = namedtuple('Bot', ('name', 'make_move'))

def create_bot(x, y):
    def func(z):
        t = z % (y + 1) - 1
        if t < 0: t += (y + 1)
        return t
    return Bot(name = 'Bot', make_move = func)
