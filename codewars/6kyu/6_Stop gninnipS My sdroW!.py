def spin_words(s):
    s = [x if len(x) < 5 else ''.join(reversed(x)) for x in s.split(' ')]
    return ' '.join(s)