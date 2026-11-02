from datetime import date
def unlucky_days(year):
    r=0
    for i in range(1,13):
        if date(year,i,13).weekday()==4:
            r+=1
    return r