# Exclude 'y' from vowels since it can't make up its mind if it's a vowel
vs = 'aeiou'

def find_solutions(words):
    w = set(words)
    r = set()
    for x in w:
        for i in range(len(x)):
            if x[i] not in vs: continue
            y = {x[:i] + v + x[i+1:] for v in vs}
            if len(y & w) == len(y):
                r.add(tuple(sorted(list(y))))
    return sorted([list(x) for x in r])