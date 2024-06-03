def even_chars(s):
    if 2 <= len(s) <= 100:
        return [s[i] for i in range(1, len(s), 2)]
    return "invalid string"
