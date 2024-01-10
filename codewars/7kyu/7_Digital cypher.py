from itertools import cycle
def encode(message, key):
    return [int(ord(x) - ord('a') + int(y) + 1) for x,y in zip(message, cycle(str(key)))]