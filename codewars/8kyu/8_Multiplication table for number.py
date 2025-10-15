def multi_table(a):
    return "\n".join(f"{i} * {a} = {i*a}" for i in range(1, 11))
