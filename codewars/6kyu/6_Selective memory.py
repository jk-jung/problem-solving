def select(s):
    s = s.split(', ')
    t = [x[1:] for x in s if x[0] == '!'] + [y for x, y in zip(s, s[1:]) if x[0] == '!']
    return ', '.join([x for x in s if x.strip('!') not in t])
