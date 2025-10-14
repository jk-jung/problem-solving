def type_validation(a, b):
    return str(type(a)).split("'")[1].split("(")[0].split(".")[-1] == b
