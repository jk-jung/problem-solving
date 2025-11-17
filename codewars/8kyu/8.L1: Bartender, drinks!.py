def get_drink_by_profession(b):
    a = [
        ("Jabroni", "Patron Tequila"),
        ("School Counselor", "Anything with Alcohol"),
        ("Programmer", "Hipster Craft Beer"),
        ("Bike Gang Member", "Moonshine"),
        ("Politician", "Your tax dollars"),
        ("Rapper", "Cristal"),
    ]
    for k, v in a:
        if k.lower() == b.lower():
            return v
    return "Beer"
