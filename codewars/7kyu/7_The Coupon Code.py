from datetime import datetime


def check_coupon(a, b, x, y) -> bool:
    if not isinstance(a, type(b)) or a != b:
        return False

    x = datetime.strptime(x, "%B %d, %Y").date()
    y = datetime.strptime(y, "%B %d, %Y").date()

    return x <= y
