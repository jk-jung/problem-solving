function chain(fns) {
    let create = (...args) => {
        let r = {}
        for (let x in fns) {
            r[x] = (...args2) => {
                let next = fns[x](...args, ...args2)
                return create(next)
            }
        }
        r['execute'] = () => args[0]
        return r
    }

    return create()
}