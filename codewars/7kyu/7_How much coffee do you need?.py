def how_much_coffee(a):
    r = 0
    for x in a:
        if x in ("cw", "dog", "cat", "movie"):
            r += 1
        if x in ("CW", "DOG", "CAT", "MOVIE"):
            r += 2
    return r if r < 4 else "You need extra sleep"
