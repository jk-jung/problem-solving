from collections import Counter
def is_isogram(w):
    try:
        return len(set(Counter([x for x in w.lower() if x.isalpha()]).values())) == 1
    except:
        return False
