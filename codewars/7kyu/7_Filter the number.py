def filter_string(s):
    return int(''.join(x for x in s if x.isdigit()))
