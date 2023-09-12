import re
def bracket_buster(s):
    if isinstance(s, str):
        return re.findall(r'\[([\w \'?\[\-]*)\]', s)
    return 'Take a seat on the bench.'
