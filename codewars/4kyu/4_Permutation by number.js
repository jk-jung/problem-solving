function permutationByNumber(word, n) {
    word = word.split('').sort().join('')

    let r = '', s = word
    let count = (x) => {
        let c = 1
        for (let i = 0, p = 1; i < x.length; i++) {
            c *= (i + 1)
            if (i > 0 && x[i - 1] === x[i]) p++
            else p = 1
            c = Math.floor(c / p)
        }
        return c
    }
    n++
    if (n > count(word)) return ''
    for (let i = 0; i < word.length; i++) {
        for (let k = 0; k < s.length; k++) {
            if (k === 0 || s[k - 1] !== s[k]) {
                let t = s.substr(0, k) + s.substr(k + 1)
                let c = count(t)

                if (n <= c) {
                    r += s[k]
                    s = t
                    break
                }
                n -= c
            }
        }
    }

    return r
}