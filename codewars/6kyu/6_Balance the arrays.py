from collections import Counter
def balance(a, b):
    return [x[1] for x in Counter(a).most_common()] == [x[1] for x in Counter(b).most_common()]
