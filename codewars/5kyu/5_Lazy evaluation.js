class Lazy {
    constructor() {
        this.v = []
    }

    add() {
        this.v.push(arguments)
        return this
    }

    invoke() {
        let args = arguments[0]
        for (let data of this.v)
            args = data[0](...Array.prototype.slice.call(data, 1), ...args)
        return args
    }
}