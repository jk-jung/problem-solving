function askForMissingDetails(v) {
    let r = []
    v.forEach(x => {
        for(let k in x) {
            if (x[k] === null) {
                x['question'] = `Hi, could you please provide your ${k}.`
                r.push(x)
            }
        }
    })
    return r
}