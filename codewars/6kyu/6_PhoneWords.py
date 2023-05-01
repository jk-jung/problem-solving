def phone_words(s):
    r, y = [], ''
    t = {
        '1': '/',
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz',
        '0': ' ',
    }
    for x in s:
        if y == x:
            i = t[x].find(r[-1])
            if i == len(t[x]) - 1:
                r.append(t[x][0])
            else:
                r[-1] = t[x][i + 1]
        else:
            r.append(t[x][0])
        y = x

    return ''.join(r).replace('/', '')