// partition the items array so that all values for which pred returns true are
// at the end, returning the index of the first true value
function partitionOn(f, v) {
    let vv = JSON.parse(JSON.stringify(v)).map((x, i) => [x, i])

    vv.sort((x, y) => {
        if (f(x[0]) === f(y[0])) return x[1] - y[1]
        return f(x[0]) ? 1 : -1
    })
    while (v.length) v.pop()
    vv.forEach(x => v.push(x[0]))
    return v.filter(x => !f(x)).length
}