def even_or_odd(s):
    a = sum([int(x) for x in s if int(x) % 2 == 0])
    b = sum([int(x) for x in s if int(x) % 2 == 1])
    if a == b: return "Even and Odd are the same"
    return "Even is greater than Odd" if a > b else "Odd is greater than Even"
