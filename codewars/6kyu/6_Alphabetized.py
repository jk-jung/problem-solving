from string import ascii_lowercase

def alphabetized(s):
    r = []
    for c in ascii_lowercase:
        r += [x for x in s if x.lower() == c]
    return ''.join(r)