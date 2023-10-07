from collections import Counter
def last_survivors(s):
    while any(v != 1 for k, v in Counter(s).items()):
        r = ''
        for k, v in Counter(s).items():
            t = chr((ord(k) + 1 - ord('a')) % 26 + ord('a'))
            r += t * (v // 2)
            r += k * (v % 2)
        s = r
    return s