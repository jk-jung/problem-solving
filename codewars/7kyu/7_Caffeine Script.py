def caffeine_buzz(n):
    if n % 3 == 0 and n % 4 == 0: return "Coffee" + ("Script" if n % 2 == 0 else "")
    if n % 3 == 0: return "Java" + ("Script" if n % 2 == 0 else "")
    return "mocha_missing!"
