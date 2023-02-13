def check_valid_tr_number(s):
    s = str(s)
    try:
        if str(int(s)) != s or len(s) != 11: return False
        a = sum(map(int, [s[0], s[2], s[4], s[6], s[8]])) * 7
        a = (a - sum(map(int, [s[1], s[3], s[5], s[7]]))) % 10
        if str(a) != s[9]: return False
        if sum(int(s[i]) for i in range(10)) % 10 != int(s[-1]): return False
        return True
    except:
        return False
