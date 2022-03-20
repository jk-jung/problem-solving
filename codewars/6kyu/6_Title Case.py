def title_case(s, w=''):
    a, *b = s.lower().split(' ')
    w = w.lower().split(' ')
    s = [a.title()] + [x.lower() if x in w else x.title() for x in b]
    return ' '.join(s)
