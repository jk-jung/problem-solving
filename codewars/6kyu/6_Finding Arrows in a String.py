import re
def arrow_search(s):
    a = re.findall('<=*', s) + re.findall('<-+', s)
    b = re.findall('=*>', s) + re.findall('-+>', s)

    r = 0
    for x in a:
        r -= len(x) * (2 if '=' in x else 1)
    for x in b:
        r += len(x) * (2 if '=' in x else 1)

    r += len(re.findall('<-+', s))
    r -= len(re.findall('-+>', s))
    return r
