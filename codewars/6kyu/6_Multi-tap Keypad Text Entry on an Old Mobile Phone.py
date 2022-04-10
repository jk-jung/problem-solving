def presses(s):
    r = 0
    for x in s.upper():
        for t in ['1', 'ABC2', 'DEF3', 'GHI4', 'JKL5', 'MNO6', 'PQRS7', 'TUV8', 'WXYZ9', ' 0', '*', '#']:
            if x in t:
                r += t.index(x) + 1
    return r