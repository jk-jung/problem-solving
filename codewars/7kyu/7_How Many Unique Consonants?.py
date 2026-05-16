def count_consonants(a):
    return len(set([x for x in a.lower() if x.isalpha() and x not in "aeiou"]))