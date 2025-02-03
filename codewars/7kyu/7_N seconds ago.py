from datetime import timedelta, datetime
def seconds_ago(s, n):
    d = datetime.strptime(s, "%Y-%m-%d %H:%M:%S")
    return str(d - timedelta(seconds=n))