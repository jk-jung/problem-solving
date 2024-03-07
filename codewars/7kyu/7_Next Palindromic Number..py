def next_pal(val):
    while True:
        val += 1
        if str(val) == str(val)[::-1]:
            return val
