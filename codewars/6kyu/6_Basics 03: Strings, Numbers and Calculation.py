def calculate_string(s):
    t = '0123456789.+-*/'
    s = ''.join(x for x in s if x in t)
    return str(round(eval(s)))
