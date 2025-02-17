import re
def read_zalgo(a):
    a = re.sub(r'[^a-zA-Z !,?.]', '', a)
    return a
