import re
def pseudo_sort(s):
    s = [x for x in re.sub('[^a-zA-Z ]', '', s).split(' ') if x]
    def f(a):
        if a[0].islower(): return [ord(x) for x in a]
        else: return [1000 - ord(x) for x in a] + ([999999] * 100)
    return ' '.join(x for x in sorted(s, key=f))
