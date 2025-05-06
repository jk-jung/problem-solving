def remove_duplicate_words(s):
    return ' '.join(x for i, x in enumerate(s.split(' ')) if i == s.split(' ').index(x))