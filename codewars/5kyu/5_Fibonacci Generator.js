function genfib(){
    let a = 0, b = 1
    return function fib(){
        let r = a
        a = b
        b += r
        return r
    }
}