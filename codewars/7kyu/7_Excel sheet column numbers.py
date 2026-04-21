def title_to_number(a):
    r = 0
    for i in range(1, len(a)):
        r += 26**i
    b = 0
    t = 0
    for x in a:
        t = t * 26 + ord(x) - ord("A")

    return r + t + 1
