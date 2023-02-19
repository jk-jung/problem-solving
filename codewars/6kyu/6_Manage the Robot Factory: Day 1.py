import math
def calculate_scrap(scraps, number_of_robots):
    r = 1
    for x in scraps:
        r = r * (100 - x) / 100
    return math.ceil(50 / r * number_of_robots)
