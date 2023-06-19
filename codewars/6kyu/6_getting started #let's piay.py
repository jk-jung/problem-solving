from math import pi

def whatpimeans(alpha = 'abcdefghijklmnopqrstuvwxyz'):
    #create a dictionnary linking alphabet to 'secret encryption'
    #dico = {85:'a', 24:'b',32:'c', [...],10:'z'}
    a = [85,24,32,64,11,52,91,79,78,99,62,27,74,35,14, 16,66,81,19,39,13,33,45,49,95,10]
    dico = {k: v for k, v in zip(a ,alpha.upper())}

    #take the number PI as string and prepare it for decoding
    crypt = str(pi).replace('.','')[::-1]
    code = []
    #reverse the string and group 2 by 2 to form a list
    for i in range(0, len(crypt), 2):
        code.append(crypt[i:i+2])

    decrypt = ''
    for x in code:
        decrypt += dico.get(int(x), '')

    return decrypt
