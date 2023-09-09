def sqr_modulus(z):
    try:
        assert all(isinstance(x, int) for x in z[1:])
        if z[0] == 'cart':
            s = sum(x ** 2 for x in z[1:])
        elif z[0] == 'polar':
            s = sum(x ** 2 for x in z[1::2])
        else: raise Exception()
        return True, s, int(''.join(sorted(str(s), reverse=True)))
    except:
        return False, -1, 1
    