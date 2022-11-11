from collections import defaultdict
def T9(w,s):
    def f(x):
        r = ''
        for c in x.lower():
            if c in 'abc': r += '2'
            if c in 'def': r += '3'
            if c in 'ghi': r += '4'
            if c in 'jkl': r += '5'
            if c in 'mno': r += '6'
            if c in 'pqrs': r += '7'
            if c in 'tuv': r += '8'
            if c in 'wxyz': r += '9'
        return r
    def g(x):
        r = ''
        for c in x:
            if c in '2': r += 'a'
            if c in '3': r += 'd'
            if c in '4': r += 'g'
            if c in '5': r += 'j'
            if c in '6': r += 'm'
            if c in '7': r += 'p'
            if c in '8': r += 't'
            if c in '9': r += 'w'
        return r
    t = defaultdict(list)
    [t[f(x)].append(x) for x in w]

    return t.get(s, [g(s)])
