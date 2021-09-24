def land_perimeter(v):
    n, m = len(v), len(v[0])
    r = 0
    for i in range(n):
        for j in range(m):
            if v[i][j] != 'X': continue
            for dy, dx in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                y = i + dy
                x = j + dx

                if y < 0 or x < 0 or y == n or x == m or v[y][x] == 'O':
                    r += 1
    return f'Total land perimeter: {r}'