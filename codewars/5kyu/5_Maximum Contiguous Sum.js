function maxContiguousSum (arr) {
    let r = 0, cur = 0
    for (let x of arr) {
        cur += x
        if(cur < 0)cur = 0
        if(r < cur)r = cur
    }
    return r
}