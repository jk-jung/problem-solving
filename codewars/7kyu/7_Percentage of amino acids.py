def aa_percentage(a, b= ["A", "I", "L", "M", "F", "W", "Y", "V"]):
    return round(sum(x in b for x in a) / len(a) * 100)