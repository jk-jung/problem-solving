import datetime
def count_days(d):
    c = datetime.datetime.now()
    if d.year == c.year and d.month == c.month and c.day == d.day:
        return "Today is the day!"
    t = d - datetime.datetime.now()
    if t.days < 0: return "The day is in the past!"

    x = 24 * 60 * 60
    k = 1 if t.seconds % x > (x / 2) else 0
    return  f'{t.days + k} days'