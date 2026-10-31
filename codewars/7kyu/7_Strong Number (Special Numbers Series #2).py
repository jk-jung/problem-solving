from math import factorial as f
def strong_num(x):
    return "STRONG!!!!" if x == sum([f(int(y)) for y in str(x)]) else "Not Strong !!"
