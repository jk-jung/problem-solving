function solveTTT(v) {
    let w = [], z = []

    let ck = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],
        [0, 3, 6], [1, 4, 7], [2, 5, 8],
        [0, 4, 8], [2, 4, 6],
    ]

    for (let i = 0; i < 9; i++) {
        if (v[i] !== '') continue

        v[i] = 'X'
        let ok = false
        for (let t of ck) {
            if (t.includes(i) && v[t[0]] === 'X' && v[t[1]] === 'X' && v[t[2]] === 'X') {
                ok = true
            }
        }
        if (ok) w.push(i)
        else z.push(i)
        v[i] = ''
    }

    return w.length > 0 ? w[0] : z[0]
}