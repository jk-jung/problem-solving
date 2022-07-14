def bowling_pins(t):
    s = list("I I I I\n I I I \n  I I  \n   I   ")
    idx = 7
    for i in range(len(s)):
        if s[i] == 'I':
            if idx in t:
                s[i] = ' '
            idx += 1
            if idx == 11: idx = 4
            elif idx == 7: idx = 2
            elif idx == 4: idx = 1
    return ''.join(s)