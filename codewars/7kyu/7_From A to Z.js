function gimmeTheLetters(sp) {
    let [a, b] = sp.split('-')
    let r = ""
    for(let i = a.charCodeAt(0);i<=b.charCodeAt(0);i++){
        r += String.fromCharCode(i)
    }
    return r
}