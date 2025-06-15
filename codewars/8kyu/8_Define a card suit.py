from preloaded import DECK

def define_suit(c):
    if c[-1] == 'C': return 'clubs'
    if c[-1] == 'D': return 'diamonds'
    if c[-1] == 'H': return 'hearts'
    if c[-1] == 'S': return 'spades'
