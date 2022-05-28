def dont_give_me_five(s, e):
    return sum(1 for x in range(s, e + 1) if '5' not in str(x))
