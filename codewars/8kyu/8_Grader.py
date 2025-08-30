def grader(a):
    if a > 1 or a < 0.6:
        return "F"
    if a >= 0.9:
        return "A"
    if a >= 0.8:
        return "B"
    if a >= 0.7:
        return "C"
    return "D"
