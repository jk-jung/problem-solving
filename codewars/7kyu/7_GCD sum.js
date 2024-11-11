function solve(s,g){
    if(s % g) return -1
    let a = Math.floor(s / g)
    if(a == 1)return -1
    return [1 * g, (a - 1) * g]
}