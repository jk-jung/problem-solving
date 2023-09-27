def flatten(d):
    r = {}
    def f(x, s=""):
        for k, v in x.items():
            kk = (s + '/' + k).strip('/')
            if isinstance(v, dict):
                if len(v) == 0: r[kk] = ''
                else: f(v, s + '/' + k)
            else: r[kk] = v

    f(d)
    return r