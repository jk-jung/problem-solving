from math import gcd

class Fraction:

    def __init__(self, a, b):
        g = gcd(a, b)
        self.top = a // g
        self.bottom = b // g

    #Equality test

    def __eq__(self, other):
        first_num = self.top * other.bottom
        second_num = other.top * self.bottom
        return first_num == second_num

    def __add__(self, o):
        a = o.top * self.bottom + self.top * o.bottom
        b = self.bottom * o.bottom
        return Fraction(a, b)

    def __repr__(self):
        return f'{self.top}/{self.bottom}'
