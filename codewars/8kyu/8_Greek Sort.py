from preloaded import greek_alphabet


def greek_comparator(a, b):
    a = greek_alphabet.index(a)
    b = greek_alphabet.index(b)

    if a == b:
        return 0
    return -1 if a < b else 1
