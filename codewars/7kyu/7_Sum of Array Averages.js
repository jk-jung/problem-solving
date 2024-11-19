const sumAverage = (a) => {
    return Math.floor(a.map(b => b.reduce((x, y) => x + y, 0) / b.length).reduce((x, y) => x + y, 0))
}