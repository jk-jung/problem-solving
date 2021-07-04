class Thing(object):
    def __init__(self, name=None):
        self.name = name
        self._actions = ['', '', '']
        self._can = {}
        getattr(self.is_a, name)

    def a(self):
        return object.__getattribute__(self, '_actions')

    def c(self):
        return object.__getattribute__(self, '_can')

    def has(self, x):
        self.a().append(('has', x))
        return self

    def having(self, x):
        self.a().append(('has', x))
        return self

    def __getattr__(self, name):
        self.a().append(name)
        try:
            if name in ('is_a', 'is_not_a', 'is_the', 'being_the', 'and_the', 'each', 'can'):
                return self
            elif self.a()[-2] in ('is_the', 'being_the', 'and_the', 'can'):
                return self
            else:
                return object.__getattribute__(self, name)
        except:
            if self.a()[-2] == 'is_a':
                object.__setattr__(self, f'is_a_{name}', True)
            elif self.a()[-2] == 'is_not_a':
                object.__setattr__(self, f'is_a_{name}', False)
            elif self.a()[-3] in ('is_the', 'being_the', 'and_the'):
                object.__setattr__(self, self.a()[-2], self.a()[-1])
            elif type(self.a()[-2]) == tuple and self.a()[-2][0] == 'has':
                cnt = self.a()[-2][1]
                if cnt == 1:
                    object.__setattr__(self, name, Thing(name))
                    return object.__getattribute__(self, name)
                else:
                    th = Thing(name[:-1])
                    object.__setattr__(self, name, tuple(th for _ in range(cnt)))
                    r = object.__getattribute__(self, name)
                    return r[0]
            elif self.a()[-2] == 'can':
                pass

            return self

    def __call__(self, *args, **kw):
        if self.a()[-2] == 'can':
            func = args[0]
            if len(args) > 1:
                trace = args[1]
                object.__setattr__(self, trace, [])

            def temp(*ar):
                func.__globals__['name'] = self.name
                r = func(*ar)
                if len(args) > 1:
                    object.__getattribute__(self, trace).append(r)
                return r
            self.c()[self.a()[-1]] = temp
        else:
            return self.c()[self.a()[-1]](*args)
