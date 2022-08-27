import math


class Shape:
    def __lt__(self, other):
        return self.s < other.s


class CustomShape(Shape):
    def __init__(self, s):
        self.s = s


class Square(Shape):
    def __init__(self, s):
        self.s = s * s


class Rectangle(Shape):
    def __init__(self, a, b):
        self.s = a * b


class Triangle(Shape):
    def __init__(self, a, b):
        self.s = a * b / 2


class Circle(Shape):
    def __init__(self, s):
        self.s = s * s * math.pi
