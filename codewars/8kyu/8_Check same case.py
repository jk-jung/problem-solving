def same_case(a, b):
    if not a.isalpha() or not b.isalpha():
        return -1
    if a.isupper() == b.isupper() or a.islower() == b.islower():
        return 1
    return 0
