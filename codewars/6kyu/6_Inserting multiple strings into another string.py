def insert_at_indexes(phrase, word, indexes):
    s = 0
    for i in indexes:
        i += s
        phrase = phrase[:i] + word + phrase[i:]
        s += len(word)
    return phrase
