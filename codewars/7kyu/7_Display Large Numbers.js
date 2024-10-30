function displayLargeNumber(n) {
    n = String(n)
    r = ''
    for(let i=0;i<n.length;i++){
        if (i % 3 == 0 && i > 0) r += ','
        r += n[n.length - i - 1]
    }
    t = ''
    for(let i=0;i<r.length;i++)t += r[r.length -1 - i]
    return t
}
