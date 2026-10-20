from collections import Counter
def count_languages(a): 
    return Counter([x['language'] for x in a])
