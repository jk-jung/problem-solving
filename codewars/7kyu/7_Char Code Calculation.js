function calc(x){
    let s = x.split("").map(x => x.charCodeAt(0)).join("")
    return s.split("").filter(x => x === '7').length * 6
}