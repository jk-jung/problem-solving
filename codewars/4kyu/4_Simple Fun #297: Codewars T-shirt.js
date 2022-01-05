C = {
    'Red': 0,
    'Blue': 1,
    'White': 2,
    'Black': 3,
    'Orange': 4,
    'Purple': 5,
}


function codewarsTshirts(n, v) {
    n = Math.floor(n / 6)

    go = (st, x) => {
        if (x === v.length) return true
        for (let t of v[x]) {
            let k = C[t]
            if (st[k]) {
                st[k]--
                if (go(st, x + 1)) return true
                st[k]++
            }
        }
        return false
    }
    return go([n, n, n, n, n, n], 0)
}