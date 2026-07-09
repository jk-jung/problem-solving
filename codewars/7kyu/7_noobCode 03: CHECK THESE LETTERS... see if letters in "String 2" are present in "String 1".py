def letter_check(a):
    return all(x.lower() in a[0].lower() for x in a[1])
