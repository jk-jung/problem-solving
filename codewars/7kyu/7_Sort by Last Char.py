def last(s):
    return [x[1] for x in sorted(enumerate(s.split(' ')), key=lambda x: (x[1][-1], x[0]))]
