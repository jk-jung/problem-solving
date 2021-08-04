function crackHash(h, y) {
    console.log(y)
    let s = 0
    let e = 200000000000000
    let r = 0

    while (h(e / 500) > y) e = Math.floor(e / 500)

    while (s <= e) {
        let m = Math.floor((s + e) / 2)
        if (h(m) <= y) {
            r = m
            s = m + 1
        } else
            e = m - 1

    }

    return r
}