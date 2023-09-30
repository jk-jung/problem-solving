import hashlib
from itertools import permutations
def sha256_cracker(h, c):
    for x in permutations(c):
        t = hashlib.sha256(''.join(x).encode()).hexdigest()
        if t == h: return ''.join(x)
    return
