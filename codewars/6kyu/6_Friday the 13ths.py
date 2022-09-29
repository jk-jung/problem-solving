import datetime
def friday_the_thirteenths(start, end=None):
    if end is None: end = start

    r = []
    for i in range(start, end + 1):
        for j in range(1, 13):
            if datetime.datetime(i, j, 13).weekday() == 4:
                r.append(f'{j}/13/{i}')
    return ' '.join(r)
