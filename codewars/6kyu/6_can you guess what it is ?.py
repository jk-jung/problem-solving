def code(x, y):
    mapping = {
        '0': '9',
        '1': '8',
        '2': '7',
        '3': '6',
        '4': '5',
        '5': '4',
        '6': '3',
        '7': '2',
        '8': '1',
        '9': '0'
    }


    x = int(''.join(mapping[k] for k in str(x)))
    y = int(''.join(mapping[k] for k in str(y)))
    return x + y
