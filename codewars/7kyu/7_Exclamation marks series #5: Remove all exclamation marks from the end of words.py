def remove(s):
    return ' '.join(x.rstrip('!') for x in s.split(' '))