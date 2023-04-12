import re
def pete_talk(speech, ok=[]):
    ok = [x.lower() for x in ok]
    def f(x):
        x = x[0].lower()
        if x in ok or len(x) <= 2: return x
        return x[0] + '*' * (len(x) - 2) + x[-1]
    r = re.sub('[a-zA-Z]+', f, speech).lower()
    for x in '.!?':
        def g(x): return x[0].upper()
        r = x.join([re.sub('^[ ]*[a-zA-Z]', g, y) for y in r.split(x)])
    return r
