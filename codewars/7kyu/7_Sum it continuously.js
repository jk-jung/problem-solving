function add(arr) {
    let r = 0
    return arr.map(x=>{
        r += x
        return r
    })
}