def get_rectangle_string(a, b):
    r = ["*" * a]
    for i in range(1, b - 1):
        r.append("*" + " " * (a - 2) + "*")
    if b > 1:
        r.append("*" * a)
    return "\r\n".join(r) + "\r\n"
