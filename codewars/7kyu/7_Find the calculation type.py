def calc_type(a, b, c) -> str:
    if a + b == c:
        return "addition"
    if a - b == c:
        return "subtraction"
    if a * b == c:
        return "multiplication"
    return "division"
