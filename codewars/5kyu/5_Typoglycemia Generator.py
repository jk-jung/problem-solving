def scramble_words(w):
    def f(s):
        t = [x for x in s if x.isalpha()]
        t = t if len(t) == 1 else t[:1] + list(sorted(t[1:-1])) + t[-1:]
        r = ''
        for x in s:
            if x.isalpha(): r += t.pop(0)
            else: r += x
        return r
    return ' '.join(f(x) for x in w.split(' '))