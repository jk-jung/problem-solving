def calculate_time(a, b):
    a = (a[0]**2 + a[1] ** 2) **.5
    b = (b[0]**2 + b[1] ** 2) **.5
    return round(a / (a - b) * 5 - 5, 3)
