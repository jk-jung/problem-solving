import re
def replace_dashes_as_one(s):
    return re.sub(r'-[\- ]*-', '-', s)
