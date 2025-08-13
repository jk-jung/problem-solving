def to_alternating_case(s):
    return ''.join((x.upper() if x.islower() else x.lower()) for x in s)
