from itertools import groupby
def look_and_say(s='1', maxlen=5):
    r = []
    for i in range(maxlen):
        g = groupby(s)
        t = ''
        for k, v in g:
            t += str(len(list(v))) + k
        r.append(t)
        s = t
    return r