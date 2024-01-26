def drop_cap(words):
    return ' '.join([x.title() if len(x) > 2 else x for x in words.split(' ')])