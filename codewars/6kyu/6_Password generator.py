import random
def password_gen():
    a = '0123456789'
    b = 'abcdefghijklmnopqrstuvwxyz'
    c = b.upper()
    r = ''
    n = random.randint(6, 20)
    for i in range(10):
        r += random.sample(a, 1)[0]
        if len(r) >= n:break
        r += random.sample(b, 1)[0]
        if len(r) >= n:break
        r += random.sample(c, 1)[0]
        if len(r) >= n:break
    return r
