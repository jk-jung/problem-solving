from itertools import groupby
def reverse(s):
    s = [(k, list(v)) for k, v in groupby(s)]
    return ''.join(''.join(v).swapcase() if len(list(v)) > 1 else k for k, v in s)
