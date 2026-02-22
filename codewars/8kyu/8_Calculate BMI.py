def bmi(w, h):
    x = w / h**2
    if x <= 18.5:
        return "Underweight"
    if x <= 25:
        return "Normal"
    if x <= 30:
        return "Overweight"
    return "Obese"
