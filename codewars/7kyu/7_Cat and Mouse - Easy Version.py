def cat_mouse(x):
    return "Escaped!" if abs(x.find("C") - x.find("m")) > 4 else "Caught!"