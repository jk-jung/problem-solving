from collections import Counter
from string import ascii_lowercase

def string_letter_count(s):
    c = Counter(s.lower())
    return ''.join(f'{c[x]}{x}' for x in ascii_lowercase if x in c)
