def apparently(s):
    r = ['']
    for x in s.split(' ') + ['']:
        if r[-1] in ('and', 'but') and x != 'apparently':
            r.append('apparently')
        r.append(x)
    return ' '.join(r[1:-1])
