def is_valid_IP(s):
    try:
        s2 = '.'.join(str(int(x)) for x in s.split('.') if 0 <= int(x) <= 255)
        return s2 == s and len(s.split('.')) == 4
    except:
        return False