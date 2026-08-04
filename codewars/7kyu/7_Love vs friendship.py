def words_to_marks(s):
    return sum(ord(c) - 96 for c in s)
