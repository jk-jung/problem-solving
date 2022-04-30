import numpy as np

def get(t, s):
    for x in s.split('\n'):
        town, data = x.split(':')
        if town == t:
            return [float(y.split(' ')[-1]) for y in data.split(',')]


def mean(t, s):
    if not get(t, s): return -1
    return np.mean(get(t, s))


def variance(t, s):
    if not get(t, s): return -1
    return np.var(get(t, s))