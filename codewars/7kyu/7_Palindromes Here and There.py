def convert_palindromes(v):
    return [int(str(x) == str(x)[::-1]) for x in v]
