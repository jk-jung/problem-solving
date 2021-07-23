function LRUCache(capacity, init) {
    let r = {}
    let cap = capacity
    let cache = (k, v) => {
        delete r[k]

        Object.defineProperty(r, k, {
            get: () => v,
            set: (val) => cache(k, val),
            enumerable: true,
            configurable: true
        })

        if (Object.keys(r).length > r.capacity)
            delete r[Object.keys(r)[0]]
        return r
    }

    let setCap = (x) => {
        cap = x
        while (Object.keys(r).length > r.capacity)
            delete r[Object.keys(r)[0]]
    }

    Object.defineProperty(r, 'size', {get: () => Object.keys(r).length})
    Object.defineProperty(r, 'capacity', {get: () => cap, set: setCap})
    Object.defineProperty(r, 'cache', {value: cache})
    Object.defineProperty(r, 'delete', {value: (k) => delete r[k]})

    if (init) Object.entries(init).forEach(x => r.cache(x[0], x[1]))
    return r
}
