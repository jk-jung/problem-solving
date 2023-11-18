def word_problem(r: List[Tuple[str, str]], a: str, b: str, n: int) -> bool:
    if a == b: return True
    if n == 0: return False
    for i in range(len(a)):
        for x, y in r:
            if a[i:].startswith(x):
                if word_problem(r, a[:i] + y + a[i + len(x):], b, n - 1):
                    return True
    return False
