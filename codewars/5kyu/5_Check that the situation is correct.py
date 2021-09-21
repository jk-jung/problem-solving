def is_it_possible(s):
    def win(k):
        for i in range(3):
            if {s[i*3], s[i*3+1], s[i*3+2]} == {k}: return True
            if {s[i], s[3 + i], s[6 + i]} == {k}: return True
        if s[4] == k:
            if s[0] == k and s[8] == k: return True
            if s[2] == k and s[6] == k: return True
        return False
    x, o = s.count('X'), s.count('0')
    wx, wo = win('X'), win('0')

    if wx and wo: return False
    if wx: return x == o + 1
    if wo: return x == o
    return x == o or x == o + 1