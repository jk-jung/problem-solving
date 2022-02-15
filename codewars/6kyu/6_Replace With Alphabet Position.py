def alphabet_position(text):
    return ' '.join(str(ord(x) - ord('a') + 1) for x in text.lower() if x.isalpha())
