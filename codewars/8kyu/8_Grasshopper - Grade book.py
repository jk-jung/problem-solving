def get_grade(*x):
    print(x)
    x = sum(x)
    if x >= 270:
        return "A"
    if x >= 240:
        return "B"
    if x >= 210:
        return "C"
    if x >= 180:
        return "D"
    return "F"
