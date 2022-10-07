def how_many_pizzas(n):
    x, y = divmod(n * n, 64)
    return f"pizzas: {x}, slices: {y // 8}"
