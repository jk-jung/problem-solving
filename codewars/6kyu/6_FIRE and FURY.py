import re
from itertools import groupby
def fire_and_fury(tweet):
    if set(tweet) - set('EFIRUY'): return "Fake tweet."
    v = groupby(re.findall('FURY|FIRE', tweet))
    s = []
    for x, y in v:
        y = list(y)
        if y[0] == 'FURY':
            s.append(f'I am {"really " * (len(y) - 1)}furious.')
        else:
            s.append(f'You {"and you " * (len(y) - 1)}are fired!')
    return ' '.join(s) if s else "Fake tweet."
