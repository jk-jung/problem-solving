def find_squares(num):
    i = 0
    while True:
        j = i + 1
        if j * j - i * i == num:
            return f"{j * j}-{i * i}"
        i = j
