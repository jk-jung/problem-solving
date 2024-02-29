def solution(a, b):
    return len(a) + 1 if not b else len(a.split(b)) - 1