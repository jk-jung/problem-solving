import re
def solve(s):
    def f(x):
        if x[4]: return 'ㄱ' * int(x[4])
        return 'ㄱ'
    s = re.sub(r'(\[backspace\])((\*)([0-9]+))?', f, s)
    r = ''
    for x in s:
        if x == 'ㄱ':r = r[:-1]
        else: r += x
    return r
