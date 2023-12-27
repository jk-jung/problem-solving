def time_per_day(l):
    return round(sum(x*y*0.75 for x, y in l) / 5 / 60, 2)