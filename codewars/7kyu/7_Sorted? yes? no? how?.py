def is_sorted_and_how(a):
    if sorted(a) == a:
        return 'yes, ascending'
    if sorted(a)[::-1] == a:
        return 'yes, descending'
    return 'no'
