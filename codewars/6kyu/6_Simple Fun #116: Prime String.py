def prime_string(s):
    for i in range(1, len(s)):
        if len(s) // i * s[:i] == s: return False
    return True
