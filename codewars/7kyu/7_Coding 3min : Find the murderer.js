function sc(said,suspects){
    s =said.replace(/~/g, '.')
    var re = new RegExp(`^${s}`, "i");
    return suspects.filter(x => x.match(re)).join(',')
}
