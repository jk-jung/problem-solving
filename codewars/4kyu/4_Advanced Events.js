function Event() {
    let fs = []

    this.subscribe = (...args) => {
        args.forEach(x => {
            if (typeof(x) == 'function')fs.push(x)
        })
    }

    this.emit = function() {
        fs.slice().forEach(x => x.apply(this, arguments))
    }

    this.unsubscribe = (...args) => {
        for(let f of args) {
            for(let i = fs.length - 1; i>=0 ;i--){
                if( fs[i] === f) {
                    fs.splice(i, 1)
                    break
                }
            }
        }
    }
}