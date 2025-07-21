def calculator(x, y, op):
    try:
        if op not in "+ - * / ":
            return "unknown value"
        if not isinstance(x, int) or not isinstance(y, int):
            return "unknown value"
        return eval(f"{x}{op}{y}")
    except:
        return "unknown value"
