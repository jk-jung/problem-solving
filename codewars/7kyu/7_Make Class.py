def make_class(*args):
    def f(self, *v):
        [setattr(self, x, y) for x, y in zip(args, v)]

    return type("Temp", (object, ), { "__init__": f, }) 