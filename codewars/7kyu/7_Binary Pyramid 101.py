def binary_pyramid(m,n):
    return bin(sum([int(bin(x)[2:]) for x in range(m,n+1)]))[2:]