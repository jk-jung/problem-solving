def format_words(w):
    try:
        w = [x for x in w if x]
        if len(w) == 0:
            return ''
        if len(w) == 1:
            return w[0]
        return ', '.join(w[:-1]) + ' and ' + w[-1]
    except:
        return ''