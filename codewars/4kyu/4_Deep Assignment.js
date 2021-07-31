function deepAssignment(obj, s, value) {
    let keys = []

    for (let i = 0; i < s.length; i++) {
        let k = ''
        if (s[i] === '[') {
            while (s[i] !== ']') k += s[i++]
            keys.push([parseInt(k.substr(1)), 1])
        } else {
            if (s[i] === '.') i++
            while (i < s.length && s[i] !== '.' && s[i] !== '[') k += s[i++]
            if (s[i] === '[') i--
            keys.push([k, 0])
        }
    }
    keys.push([0, 2])

    let o = obj
    for (let i = 1; i < keys.length; i++) {
        let k = keys[i - 1][0]
        let v = keys[i][1]
        if (v === 0) {
            if (o[k] === undefined)
                o[k] = {}
        } else if (v === 1) o[k] = new Array()
        else o[k] = value
        o = o[k]
    }
}