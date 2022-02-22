function extractIds(data){
    let r = []
    Object.entries(data).forEach(x => {
        let [k, v] = x
        if(typeof(v) === typeof({})) extractIds(v).forEach(i => r.push(i))
        if (k === 'id') r.push(v)
    })
    return r
}