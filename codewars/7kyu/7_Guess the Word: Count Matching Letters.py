def count_correct_characters(a, b):
    assert len(a) == len(b)
    return sum(x==y for x, y in zip(a, b))
