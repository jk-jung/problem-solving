let r = [], a = [], b = []
for(let i=0;i<20000;i++){
    r.push(expected)
    let n = r.length
    if(n % 2 == 0) {
        a = r.slice(0, n/2)
        b = r.slice(n/2)
        if(a[0] == b[0]) break
    }
}
let c = 0

function next() {
    return a[c++ % a.length]
}
