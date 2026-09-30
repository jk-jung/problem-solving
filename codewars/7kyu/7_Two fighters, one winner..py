def declare_winner(a, b, c):
    if b.name == c:
        a, b = b, a
        
    while True:
        b.health -= a.damage_per_attack
        if b.health <=0:
            return a. name
        a, b = b, a
