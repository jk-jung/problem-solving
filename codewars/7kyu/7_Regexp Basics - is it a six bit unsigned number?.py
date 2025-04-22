def six_bit_number(n):
    try:
        return n == str(int(n)) and 64 > int(n) >= 0
    except:
        return False