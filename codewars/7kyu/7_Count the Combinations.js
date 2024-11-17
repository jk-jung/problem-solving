function numCombo(a, n){
    let r = a.reduce((x, y) => x + y , 0)
    return a.filter(x => r - x == n).length
}
