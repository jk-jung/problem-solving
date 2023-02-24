def iam(s=None, pre=''):
    if s:
        return 'I am ' + pre + s

    def f(x=None):
        pre2 = pre + 'very '
        return iam(x, pre2)
    return f
