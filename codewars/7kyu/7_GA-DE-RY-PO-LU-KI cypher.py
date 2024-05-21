
a = 'gdrplk'
b = 'aeyoui'

t = str.maketrans(a.upper() + a + b.upper() + b, b.upper() + b + a.upper() + a)
t2 = str.maketrans(b.upper() + b + a.upper() + a, a.upper() + a + b.upper() + b)
def encode(s):
    return s.translate(t)

def decode(s):
    return s.translate(t2)
