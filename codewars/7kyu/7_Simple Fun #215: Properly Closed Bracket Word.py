def closed_bracket_word(s):
    for a, b in zip(s, s[::-1]):
        if ord(a) + ord(b) - ord('a') * 2 != 25:
            return False
    return True
