def alias_gen(a, b):
    try:
        return FIRST_NAME[a[0].upper()] + ' ' + SURNAME[b[0].upper()]
    except:
        return 'Your name must start with a letter from A - Z.'
