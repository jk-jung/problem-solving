var helloWorld = function () {
    let a = true
    let b = a + a
    let c = b + b
    let d = c + c
    let e = d + d
    let f = e + e
    let g = f + f

    let r = String.fromCharCode(g + d)
    r += String.fromCharCode(g + f + c + a)
    r += String.fromCharCode(g + f + d + c)
    r += String.fromCharCode(g + f + d + c)
    r += String.fromCharCode(g + f + d + c + b + a)
    r += String.fromCharCode(f)
    r += String.fromCharCode(a + b + c + e + g)
    r += String.fromCharCode(g + f + d + c + b + a)
    r += String.fromCharCode(g + f + e + b)
    r += String.fromCharCode(g + f + d + c)
    r += String.fromCharCode(g + f + c)
    r += String.fromCharCode(f + a)
    return r
}