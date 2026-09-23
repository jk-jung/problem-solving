def get_sum(a,b):
    a, b = sorted((a,b))
    return (a+b)*(b-a+1)//2
