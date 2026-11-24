def meeting(a):
    for i, y in enumerate(a):
        if y == 'O':
            return i
    return "None available!"
