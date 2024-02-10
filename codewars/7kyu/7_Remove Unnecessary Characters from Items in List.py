import re
def remove_char(v):
    def f(x):
        a = re.sub(r'[^\d\.]', '', x)
        b = re.sub(r'[^\d]', '', x)
        return '$' + b[:-2] + '.' + b[-2:]
    return [f(x) for x in v]