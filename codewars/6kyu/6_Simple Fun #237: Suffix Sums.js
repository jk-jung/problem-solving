function suffixSums(a) {
    let r = [], t =0
    for(let x of a) t += x

    for(let x of a) {
        r.push(t)
        t -= x
    }

    return r

}