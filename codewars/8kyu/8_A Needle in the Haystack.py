def find_needle(a):
    i = next((i for i, x in enumerate(a) if x == "needle"))
    return f"found the needle at position {i}"
