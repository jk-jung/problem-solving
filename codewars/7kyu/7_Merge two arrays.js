function mergeArrays(a, b) {
    let r = []
    for(let i=0;i<Math.max(a.length, b.length);i++){
        if(i < a.length)r.push(a[i]);
        if(i < b.length)r.push(b[i]);
    }
    return r
}
