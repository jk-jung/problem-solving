#the metaclass to be used
class LazyInit(type):
    def __new__(cls, clsname, bases, dct):
        vars = dct['__init__'].__code__.co_varnames[1:]
        func = dct['__init__']
        def check(*args):
            for k, v in zip(vars, args[1:]):
                setattr(args[0], k, v)
            return func(*args)

        dct['__init__'] = check


        return type.__new__(cls, clsname, bases, dct)
