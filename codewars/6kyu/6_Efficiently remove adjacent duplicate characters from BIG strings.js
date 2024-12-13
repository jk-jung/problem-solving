function dedup(s) {
    let r = []
    s += ' '
    for(let x of s) {
        if(r.length >= 2 && r[r.length - 1] === r[r.length - 2] && r[r.length - 1] !== x){
            let y = r[r.length - 1]
            while(r.length > 0 && r[r.length -1] === y)r.pop()
        }
        r.push(x)
    }
    return r.join('')
}
