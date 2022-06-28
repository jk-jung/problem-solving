from collections import Counter
def letter_frequency(s):
    return sorted(Counter([x for x in s.lower() if x.isalpha()]).items(), key=lambda x: (-x[1], x[0]))