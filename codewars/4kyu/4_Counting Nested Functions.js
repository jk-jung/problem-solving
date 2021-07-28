function Tracer() {}

Tracer.prototype.valueOf = () => {
    let t = new Error().stack.split("\n")
    let flag = 0, r = 0
    for (let x of t) {
        if (x.includes('unnest')) flag = 0
        if (flag) r++
        if (x.includes('Tracer.valueOf ')) flag = 1
    }
    return r - 1
}

function unnest(f) {
    let t = new Tracer()
    return f(t) / 2
}