def make_sentences(v):
    return ' '.join(v).replace(' ,', ',').replace('.', '').strip() + '.'
