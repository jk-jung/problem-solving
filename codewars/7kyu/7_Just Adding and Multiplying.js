function canReach(n, add, mult) {
    let d = {}
    function go(x) {
        if(x == 1)return true
        if(x < 1)return false
        if(d[x] !== undefined) return d[x]
        r = go(x - add)
        d[x] = r
        if(r)return true
        if(x % mult === 0)r = r || go(x / mult)
        d[x] = r
        return r
    }
    return go(n)
}