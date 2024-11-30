def make_checkered_board(n):
    line=['X' for x in range(n)]
    board = [line[:] for y in range(n)]
    for row in range(0,n):
        for col in range(0,n):
            if (row+col)%2:
                board[row][col]="O"
    return board