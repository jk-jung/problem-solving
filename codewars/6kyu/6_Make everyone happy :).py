import re
def smile(t):
    def f(x): return x[1] + x[2] + (')' if x[3] == '(' else ']')
    return re.sub(r'([:;=])([-~]?)([\(\[])', f, t)
