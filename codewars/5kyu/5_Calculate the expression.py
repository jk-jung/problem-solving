import re
def calculate(s):
    try:
        def f(x):
            return x[0].lstrip('0') or '0'
        return eval(re.sub('\d+', f, s))
    except:
        return False
