from collections import Counter
def get_strings(city):
    return ','.join([f"{k}:{'*'*v}" for k, v in Counter(city.lower()).items() if k.isalpha()])
