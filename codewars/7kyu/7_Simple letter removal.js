function solve(s, k){
    for(let x = 'a'.charCodeAt(0); x <= 'z'.charCodeAt(0); x++){
        let r = ''
        let y = String.fromCharCode(x)
        while(s.length > 0){
            if(s[0] == y && k > 0){
                k --
            }else {
                r += s[0]
            }
            s = s.slice(1)
        }
        s = r
    }
    return s
}