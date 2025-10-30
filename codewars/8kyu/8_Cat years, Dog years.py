def human_years_cat_years_dog_years(a):
    b = 0
    c = 0
    if a >= 1:
        b += 15
        c += 15
    if a >= 2:
        b += 9
        c += 9
    if a >= 3:
        b += (a - 2) * 4
        c += (a - 2) * 5
    return [a, b, c]
