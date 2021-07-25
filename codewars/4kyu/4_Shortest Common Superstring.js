// https://en.wikipedia.org/wiki/Shortest_common_supersequence_problem

function shortestCommonSuperstring(v) {
    let go = (used, s) => {
        if (Object.keys(used).length === v.length) return s
        let r = null
        for (let i = 0; i < v.length; i++) {
            if (i in used) continue
            let r2 = go({...used, [i]: 1}, merge(s, v[i]))
            if (r == null || r.length > r2.length) r = r2
        }
        return r
    }
    let merge = (x, y) => {
        if (x.includes(y)) return x
        for (let i = 0; i < x.length; i++) {
            if (y.startsWith(x.substr(i)))
                return x.substr(0, i) + y
        }
        return x + y
    }
    return go({}, '')
}
