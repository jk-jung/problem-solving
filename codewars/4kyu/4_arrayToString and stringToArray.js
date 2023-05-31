function arrayToString(v){
    r = []
    v.push(1e100)
    for(let x of v) {
        m = r.length - 1

        if(r.length == 0)r.push([x])
        else if(r[m].length == 1){
            if(m >= 1 && r[m-1].length == 1 && r[m-1][0] - r[m][0] == r[m][0] - x) {
                r[m-1].push(r.pop()[0])
                r[m-1].push(x)
            }
            else if(m >= 2 && r[m-2].length >= 4 && r[m-1].length == 1 && r[m].length == 1 && r[m-2][r[m-2].length - 1] - r[m-1][0] == r[m-1][0] - r[m][0]) {
                a = r[m-2].pop()
                c = r.pop()[0]
                b = r.pop()[0]
                r.push([a,b,c])
                r.push([x])
            }
            else {
                r.push([x])
            }
        }else {
            t = r[m].length - 1
            if(r[m][t - 1] - r[m][t] == r[m][t] - x) {
                r[m].push(x)
            }else
                r.push([x])
        }
    }
    r.pop()
    s = []
    for(let x of r) {
        if(x.length == 1)s.push(x[0].toString())
        else if(x[0] == x[1])s.push(`${x[0]}:${x.length}`)
        else if(x[0] > x[1])s.push(`${x[0]}:${x.length}${x[1]-x[0]}`)
        else s.push(`${x[0]}:${x.length}+${x[1]-x[0]}`)
    }
    return s.join(',')

}
function stringToArray(str){
    let r = []
    for(let x of str.split(',')){
        if(x.indexOf(':') != -1) {
            x = x.split(':')
            dif = 0
            if(x[1].indexOf('-') != -1) {
                dif = -parseInt(x[1].split('-')[1])
            }else if(x[1].indexOf('+') != -1)
                dif = parseInt(x[1].split('+')[1])
            for(let i=0;i<parseInt(x[1]);i++) r.push(parseInt(x[0]) + dif * i)
        }else r.push(parseInt(x))
    }
    return r
}
