def hex_word_sum(ss):
    def f(s):
        r = 0
        for x in s:
            if x == 'O': x = '0'
            if x == 'S': x = '5'
            if x.isalpha():
                t = ord(x) - ord('A') + 10
                if t > 16: return 0
            else: t = ord(x) - ord('0')
            r =  r * 16 + t
        return r
    return sum(f(x) for x in ss.split())
