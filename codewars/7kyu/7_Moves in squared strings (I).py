def vert_mirror(s):
    return '\n'.join(x[::-1] for x in s.split('\n'))
    
def hor_mirror(s):
    return '\n'.join(x for x in s.split('\n')[::-1])
    
def oper(fct, s):
    return fct(s)