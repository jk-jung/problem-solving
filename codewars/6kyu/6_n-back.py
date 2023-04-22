def count_targets(n, s):
    return len([i for i in range(n, len(s)) if s[i] == s[i-n]])
