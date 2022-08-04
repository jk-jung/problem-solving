from hashlib import md5

def crack(hash):
    for i in range(0, 100000):
        s = '%05d' % i
        if hash == md5(s.encode()).hexdigest():
            return s