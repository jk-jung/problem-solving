def initials(name):
    s = name.split(' ')
    return '.'.join(x[0].upper() for x in s) + s[-1][1:]
