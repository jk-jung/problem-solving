def capitals_first(text):
    t = [x for x in text.split(' ') if x[0].isalpha()]
    return ' '.join([x[1] for x in sorted(enumerate(t), key=lambda x: (not x[1][0].isupper(), x[0]))])
