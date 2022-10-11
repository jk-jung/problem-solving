def args_to_string(args):
    def f(x):
        if isinstance(x, str): return x
        if len(x) == 1: return x[0]
        if len(x[0]) == 1: return f"-{x[0]} {x[1]}"
        return f"--{x[0]} {x[1]}"
    return ' '.join(f(x) for x in args)
