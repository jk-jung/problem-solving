def weather_info(temp):
    c = f(temp)
    if c > 0:
        return f"{c} is above freezing temperature"
    else:
        return f"{c} is freezing temperature"


def f(t):
    return (t - 32) * 5 / 9.0
