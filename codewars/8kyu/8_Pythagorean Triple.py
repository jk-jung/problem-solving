# input is an unsorted list of 3 positive integers
def pythagorean_triple(a):
    # return True if it is possible to form a Pythagorean triple with the 3 integers
    # return False if it is not possible
    a.sort()
    return a[0] ** 2 + a[1] ** 2 == a[2] ** 2
