def is_same_language(a): 
    return len(set([x['language'] for x in a])) == 1
