def func_or(a,b):
    if a: return True
    if b: return True
    return False

def func_xor(a,b):
    a = not not a
    b = not not b
    return a != b
