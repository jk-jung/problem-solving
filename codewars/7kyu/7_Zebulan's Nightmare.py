import re
def zebulans_nightmare(s):
    return re.sub('_([a-z])', lambda x: x[1].upper(), s)
