def sillycase(s):
    m = (len(s) + 1) // 2
    return s[:m].lower() + s[m:].upper()
