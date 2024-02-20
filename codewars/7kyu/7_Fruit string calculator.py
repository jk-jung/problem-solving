def calculate(s):
    s = s.split(' ')
    t = [int(x) for x in s if x.isdigit()]
    return t[0] - t[1] if 'loses' in s else sum(t)