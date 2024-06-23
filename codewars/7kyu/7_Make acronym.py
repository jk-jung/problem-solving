def to_acronym(s):
    return ''.join(x[0] for x in s.split(' ')).upper()
