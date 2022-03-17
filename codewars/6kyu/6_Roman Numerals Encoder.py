d = ['IV', 'XL', 'CD', 'MM']

def solution(n):
    r = ''
    for i in range(4):
        x = n % 10
        if x == 9: r = d[i][0] + d[i + 1][0] + r
        elif x == 4: r = d[i] + r
        else:
            while x % 5:
                r = d[i][0] + r
                x -= 1
            if x >= 5: r = d[i][1] + r
        n //= 10
    return r