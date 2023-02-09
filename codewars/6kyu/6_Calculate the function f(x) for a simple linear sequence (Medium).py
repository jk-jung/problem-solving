def get_function(s):
    a, d = s[0], s[1] - s[0]
    for i in range(1, 5):
        if s[i-1] - s[i] != -d: return 'Non-linear sequence'
    return lambda x: a + d * x
