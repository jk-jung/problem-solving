def multiples(a, b, c) -> list[int]:
    return [x for x in range(1, c + 1) if x % a == 0 and x % b == 0]
