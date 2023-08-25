s = ' _     _  _     _  _  _  _  _ \n' + '| |  | _| _||_||_ |_   ||_||_|\n' + '|_|  ||_  _|  | _||_|  ||_| _|\n'

s = list(zip(*s[:-1].split('\n')))
r = {}
for k, i in enumerate(range(0, len(s), 3)):
    r[tuple(s[i:i + 3])] = k

def parse_bank_account(s):
    s = list(zip(*s[:-1].split('\n')))
    k = 0
    for i in range(0, len(s), 3):
        k = k * 10 + r[tuple(s[i:i + 3])]
    return k
