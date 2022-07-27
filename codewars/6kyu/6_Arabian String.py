def camelize(s):
    r = ''
    for x in s:
        if x.isalnum(): r += x
        else: r += ' '
    return ''.join(x.capitalize() for x in r.split(' '))