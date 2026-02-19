def solution(a, b):
    if len(a) > len(b):
        a, b = b, a
    return a + b + a
