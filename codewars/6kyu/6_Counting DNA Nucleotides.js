function getCountedNucleotides(v){
    let r = {'A': 0, 'C': 0, 'G': 0, 'T': 0}
    for(let i =0;i<v.length;i++){
        r[v.toUpperCase()[i]] ++
    }
    return r
}