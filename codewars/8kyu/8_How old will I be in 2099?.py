def calculate_age(a, b):
    a = b - a
    if a < 0:
        return f"You will be born in {-a} year{'s' if a < -1 else ''}."
    if not a:
        return "You were born this very year!"
    return f"You are {a} year{'s' if a > 1 else ''} old."
