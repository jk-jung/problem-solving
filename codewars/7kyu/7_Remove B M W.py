def remove_bmw(s):
    if not isinstance(s, str):
        raise TypeError("This program only works for text.")
    for x in "BMWbmw":
        s = s.replace(x, "")
    return s
