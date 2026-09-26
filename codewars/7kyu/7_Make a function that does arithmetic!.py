def arithmetic(a, b, o):
    o = {'add': '+', 'subtract': '-', 'multiply': '*', 'divide': '/'}[o]
    return eval(f'{a}{o}{b}')
