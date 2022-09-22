def test_it(a, b):
    a = sum(map(int, str(a)))
    b = sum(map(int, str(b)))
    return a * b
