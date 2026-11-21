def solve(s,k):
    k = len(s) - k
    return max(int(s[i:i + k]) for i in range(len(s)))