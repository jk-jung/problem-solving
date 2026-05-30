def find_ball(t):
    a = [i for i in range(8)]
    
    while len(a) > 1:
        n = len(a) // 2
        a, b = a[:n], a[n:]
        
        if t.get_weight(a, b) > 0:
            a = b
    return a[0]      
