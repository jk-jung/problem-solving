def manipulate(n):
    s = str(n)
    return int(s[:len(s) // 2] + '0' * ((len(s) + 1) // 2))
