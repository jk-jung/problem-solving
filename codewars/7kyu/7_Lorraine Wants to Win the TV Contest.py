def unscramble(y):
    return [x for x in word_list if sorted(x) == sorted(y)]
