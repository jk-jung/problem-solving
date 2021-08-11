// Let's make a Cat constructor!
let r = []
var Cat = function (n, w) {
    console.log(n, w)
    if (!n || !w) throw Error()
    r.push(this)
    this.name = n
    this.averageWeight = undefined

    Object.defineProperty(this, 'weight', {get: () => w, set: (x) => w = x})
};

Object.defineProperty(Cat, 'averageWeight', {
    value: () => {
        let s = 0
        for (let x of r) s += x.weight
        return s / r.length
    }
})