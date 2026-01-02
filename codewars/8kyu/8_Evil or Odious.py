def evil(n):
    return "It's " + ("Odious!" if bin(n).count("1") % 2 else "Evil!")
