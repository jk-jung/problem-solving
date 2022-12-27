import re
def find_longest_substr(s):
    r = max(re.finditer(r'([A-Za-z0-9])\1*', s), key=lambda x: x.end() - x.start())
    i, j = r.start(), r.end()
    return [str(ord(s[i])), j - i, [i, j - 1]]
