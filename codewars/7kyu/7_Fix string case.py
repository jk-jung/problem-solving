def solve(s):
    a = len([x for x in s if x.islower()])
    b = len([x for x in s if x.isupper()])
    if a >= b:
        return s.lower()
    return s.upper()