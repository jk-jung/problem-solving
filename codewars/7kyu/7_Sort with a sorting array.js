function sort(a, b) {
    let r = []
    for(let i=0;i<b.length;i++)
        for(let j=0;j<b.length;j++)if(b[j] === i)r.push(a[j])
    return r
}