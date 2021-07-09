function countTheLies(n, introduction) {
    let g = new Array(n * 3)
    for (let i = 0; i < n * 3; i++) g[i] = i


    let find = (x) => {
        if (g[x] !== x) g[x] = find(g[x])
        return g[x]
    }
    let div3 = (x) => {
        return [Math.trunc(x / 3), x % 3]
    }

    let merge = (x, y, diff) => {
        x = x * 3
        y = y * 3
        let [gx, px] = div3(find(x))
        let [gy, py] = div3(find(y))

        if (gx === gy)
            return (px + diff) % 3 === py

        for (let i = 0; i < 3; i++) {
            let ix = (px + diff + i) % 3
            let iy = (py + i) % 3

            g[gy * 3 + iy] = gx * 3 + ix
        }
        return true
    }

    let r = 0
    for (let i = 0; i < introduction.length; i++) {
        let t = introduction[i]

        if (t[1] > n || t[2] > n)
            r++
        else if (!merge(t[1] - 1, t[2] - 1, t[0] - 1))
            r++
    }

    return r
}