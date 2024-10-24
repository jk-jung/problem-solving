function sortItOut(c){
    a = c.filter(x => Math.floor(x) % 2 == 1)
    b = c.filter(x => Math.floor(x) % 2 == 0)

    return a.sort((x, y) => x - y).concat(b.sort((x, y) => y - x))
}