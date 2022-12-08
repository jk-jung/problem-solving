def get_count(n):
    r = 0
    for i in range(len(str(n))):
        for j in range(len(str(n))):
            if i <= j and j - i + 1 < len(str(n)):
                try:
                    if n % int(str(n)[i:j + 1]) == 0:
                        r += 1
                except:
                    pass
    return r