def camel_case(s):
    return ''.join(x[0].upper() + x[1:] for x in s.split(' ') if x)
