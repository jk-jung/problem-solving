import re
def count_smileys(arr):
    return len([x for x in arr if re.compile('[:;][-~]?[)D]').match(x)])