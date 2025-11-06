def final_grade(a, b):
    if a > 90 or b > 10:
        return 100
    if a > 75 and b > 4:
        return 90
    if a > 50 and b > 1:
        return 75
    return 0
