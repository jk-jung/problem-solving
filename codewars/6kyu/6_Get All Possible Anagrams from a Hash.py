from itertools import permutations
def get_words(h):
    r = ''.join(''.join(v * k) for k,v in h.items())
    return sorted({''.join(x) for x in permutations(r)})
