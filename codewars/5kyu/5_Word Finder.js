function Dictionary(words) {
    this.words = words;
}

Dictionary.prototype.getMatchingWords = function(pat) {
    let r = []
    for(let w of this.words){
        if(w.length != pat.length) continue
        let ok = true
        for(let i=0;i<w.length;i++){
            if (pat[i] == '?') continue
            if (pat[i] != w[i]) ok = false
        }
        if(ok)r.push(w)
    }
    return r
}