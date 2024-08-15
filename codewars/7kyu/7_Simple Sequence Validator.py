def validate_sequence(s):
    return len({y - x for x, y in zip(s, s[1:])}) == 1
