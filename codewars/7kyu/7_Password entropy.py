import math
def entropy(s):
    t = 0
    t += 26 if any([x.isupper() for x in s]) else 0
    t += 26 if any([x.islower() for x in s]) else 0
    t += 10 if any([x.isdigit() for x in s]) else 0
    t += 32 if any([not x.isalnum() for x in s]) else 0
    return len(s) * math.log2(t)
