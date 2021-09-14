function getLines(n) {
    if (n <= 0) return -1
    if (!n) return -1

    let r = ['1']
    for (let i = 1; i < n; i++) {
        let t = r[r.length - 1] + 'Z'
        let cnt = 0, y = '-1', s = ''

        for (let x of t) {
            if (x !== y) {
                if (cnt > 0) s += cnt.toString() + y
                cnt = 1
                y = x
            } else cnt++
        }
        r.push(s)
    }
    return r.join(',')
}