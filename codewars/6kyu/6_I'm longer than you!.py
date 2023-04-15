def longer(s):
    return ' '.join(sorted(s.split(' '), key=lambda x: (len(x), x)))
