pair = {'[': ']', '{': '}', '(': ')'}

def parse_molecule (s):
    s += '_'
    i = 0
    r = {}
    last = {}

    def merge(x, y):
        for k, v in y.items(): x[k] = x.get(k, 0) + v
        y.clear()

    def mul(y, x):
        for k in y: y[k] *= x

    while i < len(s):
        x = s[i]
        if x in '[{(':
            merge(r, last)
            y = pair[x]
            c = 1
            i += 1
            t = ''
            while c:
                if s[i] == x: c += 1
                if s[i] == y: c -= 1
                t += s[i]
                i += 1
            last = parse_molecule(t[:-1])
        elif x.isdigit():
            k = ''
            while s[i].isdigit():
                k += s[i]
                i+= 1
            mul(last, int(k))
            merge(r, last)
        elif s[i].isalpha():
            merge(r, last)
            k = s[i]
            i += 1
            while s[i].isalpha() and s[i].lower() == s[i]:
                k += s[i]
                i+= 1
            last = {k: 1}
        else:
            break
    merge(r, last)

    return r