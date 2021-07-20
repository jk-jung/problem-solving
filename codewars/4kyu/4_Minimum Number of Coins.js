function minCoins(amount) {
    let re = /^(£([0-9]+)p?|([0-9]+)p?|£?([0-9]+\.[0-9]+)p?)$/
    let r = re.exec(amount)

    if (!r) return "Invalid input - enter a positive amount of money"

    let t = [200, 100, 50, 20, 10, 5, 2, 1]
    let p = 0
    if (r[2]) p = parseInt(r[2]) * 100
    if (r[3]) p = parseInt(r[3])
    if (r[4]) p = Math.round(parseFloat(r[4]) * 100)
    if (p === 0) return "Invalid input - enter a positive amount of money"

    let rr = []
    for (let x of t) {
        let k = Math.floor(p / x);
        if (k > 0)
            rr.push([k, x])
        p %= x
    }

    let coin = (x) => x >= 100 ? `£${Math.floor(x / 100)}` : `${x}p`
    rr = rr.map(x => `${x[0]} ${coin(x[1])} coin${x[0] > 1 ? 's' : ''}`)
    let s = ''
    for (let i = 0; i < rr.length; i++) {
        s += rr[i]
        if (i !== rr.length - 1) {
            if (i === rr.length - 2) s += ' and '
            else s += ', '
        }
    }
    return s
}