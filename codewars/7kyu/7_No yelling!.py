def filter_words(s):
    for i in range(100):s = s.strip().replace('  ', ' ')
    return s[0].upper() + s[1:].lower()
