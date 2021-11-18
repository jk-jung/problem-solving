let last = null
let getMid = (x) => {
    return Math.floor((last[x][0] + last[x][1]) / 2)
}

function tryCode(r) {
    if (r == null) {
        last = [[0, 9], [0, 9], [0, 9]]
        return [4, 4, 4]
    }

    let nxt = [0, 0, 0]
    for (let i = 0; i < 3; i++) {
        let m = getMid(i)
        if (r[i] == -1) last[i][1] = m
        else if (r[i] == 1) last[i][0] = m
        nxt[i] = getMid(i)
    }
    return nxt
}