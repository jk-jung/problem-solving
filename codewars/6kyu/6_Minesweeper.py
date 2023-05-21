def board(v):
    for i in range(len(v)):
        for j in range(len(v[0])):
            if v[i][j] == ' ':
                t = 0
                if v[i-1][j] == '*': t += 1
                if v[i+1][j] == '*': t += 1
                if v[i-1][j-1] == '*': t += 1
                if v[i-1][j+1] == '*': t += 1
                if v[i+1][j-1] == '*': t += 1
                if v[i+1][j+1] == '*': t += 1
                if v[i][j-1] == '*': t += 1
                if v[i][j+1] == '*': t += 1
                if t > 0:
                    v[i] = v[i][:j] + str(t) + v[i][j+1:]
    return v
