import re
def calculator(txt):
    r = re.findall(r'(\.+)|(\+|\-|\*|//)', txt)
    a, b = len(r[0][0]), len(r[2][0])
    return '.' * eval(f'{a}{r[1][1]}{b}')
