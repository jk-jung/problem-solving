a = 'A, A#, B, C, C#, D, D#, E, F, F#, G, G#'.split(', ')
b = 'A, Bb, B, C, Db, D, Eb, E, F, Gb, G, Ab'.split(', ')
def transpose(s, i):
    def f(x):
        j = a.index(x) if x in a else b.index(x)
        return a[(i + j + len(a)) % len(a)]
    return [f(x) for x in s]
