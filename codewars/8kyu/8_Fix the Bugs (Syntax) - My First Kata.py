def my_first_kata(a, b):
    if type(a) != type(0) or type(b) != type(0):
        return False
    else:
        return a % b + b % a
