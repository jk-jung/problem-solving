from math import lcm, gcd

def game(n):
    r = 0
    for i in range(n):
        r += i * 2 + 1
    return [r // 2] if r % 2 == 0 else [r, 2]