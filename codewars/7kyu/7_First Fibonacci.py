def solution(a, b):
    while b - a >= 0 and b - a <= a:
        a, b = b - a, a
    return a, b
