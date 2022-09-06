import re
def get_consective_items(items, key):
    return max(map(len, re.findall(rf'{key}*', str(items))))