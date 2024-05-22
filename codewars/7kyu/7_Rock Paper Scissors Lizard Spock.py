t = ['scissors', 'paper', 'rock', 'lizard', 'spock']
t2 = ['scissors', 'lizard', 'paper', 'spock', 'rock']

def f(a, b, t):
    a = t.index(a)
    b = t.index(b)

    if (a + 1) % 5 == b: return 'Player 1 Won!'
    if (b + 1) % 5 == a: return 'Player 2 Won!'
    return 'Draw!'
def rpsls(a, b):
    x = f(a, b, t)
    y = f(a, b, t2)
    if x == 'Draw!' and y == 'Draw!':
        return 'Draw!'
    if x != 'Draw!': return x
    if y != 'Draw!': return y
