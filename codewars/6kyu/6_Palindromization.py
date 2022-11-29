def palindromization(s, n):
    if not s or n < 2: return "Error!"
    s = (s * n)[:(n + 1) // 2]
    t = s[:-1] if n % 2 else s
    return s + t[::-1]
