def comfortable_word(word):
    a = 'qwertasdfgzxcvb'
    b = 'yuiophjklnm'
    t = -1
    for x, y in zip(word, word[1:]):
        if x in a and y in a:
            return False
        if x in b and y in b:
            return False

    return True