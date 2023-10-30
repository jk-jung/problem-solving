def promotion(b):
    r = []
    for i in range(8):
        for j in range(8):
            if b[i][j] == 'K':
                for k in range(8):
                    if b[7][k] == 'P':
                        x = abs(j - k)
                        y = 7 - i

                        if x == y:
                            r.append('queen')
                            r.append('bishop')
                        if x == 0 or y == 0:
                            r.append('queen')
                            r.append('rook')
                        if x == 1 and y == 2:
                            r.append('knight')
                        if x == 2 and y == 1:
                            r.append('knight')

    return r