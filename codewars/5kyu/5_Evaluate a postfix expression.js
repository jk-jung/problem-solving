function postfixEvaluator(string) {
    let v = string.split(' ')
    let r = []
    for(let x of v) {
        if('+-/*'.indexOf(x) !== -1) {
            let a = r.pop()
            let b = r.pop()
            r.push(Math.floor(eval(`${b} ${x} ${a}`)))
        }else {
            r.push(x)
        }
    }
    return r[0]
}