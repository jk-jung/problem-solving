from collections import Counter
def count_vegetables(s):
    t = ["cabbage", "carrot", "celery", "cucumber", "mushroom", "onion", "pepper", "potato", "tofu", "turnip"]
    return sorted([(v, k) for k, v in Counter(s.split(' ')).items() if k in t], reverse=True)
