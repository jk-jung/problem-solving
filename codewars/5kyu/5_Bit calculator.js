function calculate(a, b) {
    let f = (x) => {
        let r = 0
        for (let i = x.length - 1, v = 1; i >= 0; i--, v *= 2) {
            if (x[i] == '1') r += v
        }
        return r
    }
    return f(a) + f(b)
}
