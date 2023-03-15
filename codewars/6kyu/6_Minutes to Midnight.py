import datetime


def minutes_to_midnight(d):
    t = datetime.datetime(d.year, d.month, d.day, 0, 0, 0) + datetime.timedelta(days=1)
    return f"{round((t - d).total_seconds() / 60)} minutes"
