import re


def validate_usr(s):
    return bool(re.match("^[a-z0-9_]{4,16}$", s))
