def solve(t):
    r, s = 0, 0

    for i in range(len(t)):
        x = ord('Z') - ord(t[i])
        r = (r + x + s * x) % 1000000007
        s = (s * 26 + x) % 1000000007

    return r
