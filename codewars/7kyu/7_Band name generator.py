def band_name_generator(a):
    if a[0] == a[-1]:
        return a.title() + a[1:]
    return "The " + a.title()
