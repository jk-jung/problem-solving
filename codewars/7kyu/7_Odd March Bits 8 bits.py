def bit_march (n : int) -> list:
    return [[int(x) for x in "0" * (8 - n - i) + "1" * n + "0" * i] for i in range(8 - n + 1) ]