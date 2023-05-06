import re
def frogify(s):
    def f(m): return ' '.join(m[1].split(' ')[::-1]).strip() + m[2]
    s = re.sub('[^a-z .!?]', '', s)
    s = re.sub('([a-z ]*)([.!?] *)', f, s)
    return re.sub(' +', ' ', s).strip()