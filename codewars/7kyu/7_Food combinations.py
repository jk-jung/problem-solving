def actually_really_good(v):
    if not v: return "You know what's actually really good? Nothing!"
    if len(v) == 1:
        return f"You know what's actually really good? {v[0].capitalize()} and more {v[0].lower()}."
    return f"You know what's actually really good? {v[0].capitalize()} and more {v[1].lower()}."
