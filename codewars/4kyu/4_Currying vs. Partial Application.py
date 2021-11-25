import types

def try_(f, args):
    for i in range(len(args) + 1, -1, -1):
        try: return f(*args[:i])
        except: pass
    raise Exception()

def curry_partial(f, *args):
    if not isinstance(f, types.FunctionType): return f

    try: return try_(f, args)
    except: return lambda *t: curry_partial(f, *args, *t)