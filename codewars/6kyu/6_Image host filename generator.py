from random import sample

def generateName():
    while True:
        t = ''.join(sample('ABCDEFGHIJKLMNOPQRSTUVWXYZ', 1)[0] for _ in range(6))
        if not photoManager.nameExists(t):
            break
    return t