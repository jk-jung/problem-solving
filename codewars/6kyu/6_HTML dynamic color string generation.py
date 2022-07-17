import random


def generate_color_rgb():
    b = ('0' + hex(random.randrange(0, 255))[2:])[-2:]
    a = ('0' + hex(random.randrange(0, 255))[2:])[-2:]
    c = ('0' + hex(random.randrange(0, 255))[2:])[-2:]
    return f"#{a}{b}{c}"

