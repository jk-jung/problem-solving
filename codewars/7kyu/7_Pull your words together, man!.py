def sentencify(words):
    words[0] = words[0][0].upper() + words[0][1:]
    return ' '.join(words) + '.'
