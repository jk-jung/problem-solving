import calendar
from collections import Counter
from datetime import date, timedelta


def most_frequent_days(year):
    s = date(year, 1, 1)
    c = Counter()
    while s.year == year:
        c[s.weekday()] += 1
        s += timedelta(1)
    r = sorted([k for k in c if c[k] == c.most_common(1)[0][1]])
    return [calendar.day_name[x % 10] for x in r]