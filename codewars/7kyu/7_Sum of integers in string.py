import re
def sum_of_integers_in_string(s):
    return sum(int(x) for x in re.sub(r'[^0-9]', ' ', s).split())
