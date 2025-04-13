function twins(a){
    let r = {}
    for(let x of a) {
        if(r[x] === undefined)r[x] = 0
        r[x] += 1
    }
    for(let x of a) {
        if(r[x] !== 2)return false
    }
    return true
}