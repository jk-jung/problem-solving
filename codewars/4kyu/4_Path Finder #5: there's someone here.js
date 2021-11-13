
function pathFinder(maze, endTurn){
    maze = maze.split('\n')
    let n = maze.length
    let x = 0, y = 0
    let mx = n-1, my = n-1
    let wx = 0, wy = 0

    let pos = (ty, tx, way) => {
        if (way == 'N') return [ty - 1, tx]
        if (way == 'S') return [ty + 1, tx]
        if (way == 'E') return [ty, tx + 1]
        return [ty, tx - 1]
    }

    let move = (way) => {
        let t = pos(y, x, way)
        let t2 = pos(my, mx, endTurn(way))
        y = t[0], x = t[1]
        my = t2[0], mx = t2[1]
    }

    for(let i=0;i<n;i++)for(let j=0;j<n;j++)if(maze[i][j] == 'W') wy = i, wx = j

    while(x < wx - 1) move('E')
    while(y < wy - 1) move('S')

    while(mx != wx - 1) move('S'), move('N')
    while(my != wy + 1 && my != wy)move('S'), move('N')

    while(x < n - 1) move('E')
    while(y < n - 1) move('S')
}
