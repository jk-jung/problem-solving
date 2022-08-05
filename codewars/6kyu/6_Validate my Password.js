function validPass(s) {
    if (s.length < 4 || s.length > 19) return 'INVALID'
    let ok1 = false, ok2 = false
    for (let x of s.toLowerCase()) {
        if (x.match(/[0-9]/)) ok1 = true
        else if (x.match(/[a-z]/)) ok2 = true
        else return 'INVALID'
    }
    return (ok1 && ok2) ? 'VALID' : 'INVALID'
}