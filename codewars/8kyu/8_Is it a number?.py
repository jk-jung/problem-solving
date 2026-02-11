def is_digit(s):
    try:
        float(s)
        return True
    except:
        return False
