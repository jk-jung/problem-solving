def rental_car_cost(d):
    t = d * 40
    if d >= 3:
        t -= 20
    if d >= 7:
        t -= 30
    return t
