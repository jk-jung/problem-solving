def distinct_digit_year(year):
    while True:
        year += 1
        if len(set(list(str(year)))) == 4:
            return year