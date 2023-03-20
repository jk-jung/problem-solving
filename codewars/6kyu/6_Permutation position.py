def permutation_position(s):
    r = 0
    for i in range(len(s)):
        d = ord(s[i]) - ord('a')
        r += d * 26 ** (len(s) - i - 1)
    return r + 1
