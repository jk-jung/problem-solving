def make_looper(s):
    i = 0
    def f():
        nonlocal i
        x = s[i % len(s)]
        i += 1
        return x
    return fㅡ