from collections import Counter
def find_the_missing_tree(c):
    c = Counter(c)
    r = Counter(c.values()).most_common()[0][0]
    return [k for k, v in c.items() if v != r][0]

