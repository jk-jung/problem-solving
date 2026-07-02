from math import pi
import re


def tire_rotations(s, t):
    a, b, c = re.split("[^0-9]+", s)

    d = 25.4 * int(c) + int(a) * int(b) / 50.0
    return t / d / pi * 1000000
