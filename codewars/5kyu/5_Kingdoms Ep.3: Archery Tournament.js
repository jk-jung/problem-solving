function countAndSort(t) {
    let r = {}
    let n = t.length
    let m = Math.floor(n / 2)

    for(let i=0;i<n;i++){
        for(let j=0;j<n;j++){
            let x = t[i][j], s = m - Math.max(Math.abs(i - m), Math.abs(j - m)) + 1, sz = 1
            if (x === '*') continue
            if (x === x.toUpperCase()) {
                x = x.toLowerCase()
                sz = 2
            }
            if (!(x in r)) r[x] = []
            while(sz --) r[x].push(s)
        }
    }

    r = Object.entries(r)
    r.sort(function (a, b) {
        sa = a[1].reduce((x, y) => x + y)
        sb = b[1].reduce((x, y) => x + y)

        if(sa > sb) return 1
        else if(sa < sb) return -1

        if (a[1].length < b[1].length) return 1
        else if(a[1].length > b[1].length) return -1

        if (a[0] > b[0]) return 1
        return -1
    });

    return r.map(x => x[0])
}