function gridIndex(grid, indices) {
    let r = ""
    let n = grid.length
    indices.forEach(x => r += grid[Math.floor((x - 1) / n)][(x - 1) % n])
    return r
}