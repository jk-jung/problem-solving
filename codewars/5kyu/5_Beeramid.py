def beeramid(bonus, price):
    n = max(bonus / price, 0)
    for i in range(1, 100000):
        if i * i > n: return i - 1
        n -= i * i
