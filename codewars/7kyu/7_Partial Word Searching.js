function wordSearch(a, b){
    a = a.toLowerCase()
    r = b.filter(x => x.toLowerCase().indexOf(a) != -1)
    return r.length === 0 ? ["Empty"] : r;
}