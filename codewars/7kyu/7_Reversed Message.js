function reverseMessage(str) {
    if (!str)return str
    r = str.split(' ')
    t = []
    for(let i=r.length - 1;i>=0;i--){
        tt = r[i].split("").reverse().join("").toLowerCase()
        tt = tt[0].toUpperCase() + tt.slice(1)
        t.push(tt)
    }
    return t.join(" ")
}
