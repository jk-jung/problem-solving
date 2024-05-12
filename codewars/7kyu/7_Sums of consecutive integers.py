# Given the number of consecutive integers and the total of the integers,
# return the consecutive integer at the requested position.
#
# Input:
#    x number of consecutive integers
#    y sum of consecutive integers
#    n position of requested integer
#
# return integer at requested position

def position(x,y,n):
    if x % 2 == 0:
        m = x // 2
        s = y // m // 2 - m + 1
        return s + n
    else:
        s = y // x - x // 2
        return s + n