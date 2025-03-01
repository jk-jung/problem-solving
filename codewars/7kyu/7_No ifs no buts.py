def no_ifs_no_buts(a, b):
    c = round((a - b) / abs(a - b + 1e-9))
    return [
        f"{a} is equal to {b}",
        f"{a} is greater than {b}",
        f"{a} is smaller than {b}",
    ][c]
