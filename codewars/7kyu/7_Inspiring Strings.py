def longest_word(x):
    return sorted(x.split(' '), key=lambda x: len(x))[-1]