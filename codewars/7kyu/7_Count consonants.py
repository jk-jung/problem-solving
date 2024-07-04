def consonant_count(s):
    return len([x for x in s.lower() if x not in 'aeiou' and x.isalpha()])
