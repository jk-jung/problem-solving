def is_pangram(s):
    return len(set(x for x in s.lower() if x.isalpha())) == 26