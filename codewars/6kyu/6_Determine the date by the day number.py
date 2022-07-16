import datetime
def get_day(day, is_leap):
    x = datetime.date(2024 if is_leap else 2023,1,1)
    for i in range(day - 1):
        x += datetime.timedelta(days=1)
    return x.strftime("%B, %-d")
