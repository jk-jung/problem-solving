function createDict(keys, values){
    const r = {}
    for(let i=0;i<keys.length;i++)r[keys[i]] = values[i] === undefined ? null : values[i]
    return r
}
