function select (a, b){
    let y = a.sort()[a.length - 3][2]
    return b.filter(x => x[0] == y)[0] || "Nothing here"
}