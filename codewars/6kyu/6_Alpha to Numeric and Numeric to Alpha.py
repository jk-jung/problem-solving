import re
def AlphaNum_NumAlpha(s):
    def f(x):
        x = x[0]
        if x.isdigit(): return chr(ord('a') + int(x) - 1)
        return alphabetnums[x]

    return re.sub(r'([a-z]|[0-9]+)', f, s)
