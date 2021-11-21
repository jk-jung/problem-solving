function parse(str) {
    let pos = 0
    let read_value = () => {
        while (str[pos] === ' ') pos++
        let k = str[pos]

        if (k === "{") {
            pos++
            let r = {}, need_next = false
            while (true) {
                while (' '.includes(str[pos])) pos++
                if (str[pos] === '}') {
                    pos++
                    break
                }
                let k = read_value()
                if (k === undefined) throw 'Invalid input'
                if (typeof (k) !== 'string') throw 'Invalid input'
                while (' :'.includes(str[pos])) pos++
                r[k] = read_value()
                need_next = false
                while (' '.includes(str[pos])) pos++
                if (str[pos] === '}') {
                    pos++
                    break
                }
                if (str[pos] !== ',') throw 'Invalid input'
                need_next = true
                pos++
                while (' '.includes(str[pos])) pos++
            }
            if (need_next) throw 'Invalid input'
            return r
        } else if (k === "[") {
            pos++
            let r = [], need_next = false
            while (true) {
                while (' '.includes(str[pos])) pos++
                if (str[pos] === ']') {
                    pos++
                    break
                }
                let v = read_value()
                if (v === undefined) throw 'Invalid input'
                need_next = false
                r.push(v)
                while (' '.includes(str[pos])) pos++
                if (str[pos] === ']') {
                    pos++
                    break
                }
                if (str[pos] !== ',') throw 'Invalid input'
                need_next = true
                pos++
                while (' '.includes(str[pos])) pos++
            }
            if (need_next) throw 'Invalid input'
            return r
        } else if (k === ']') {
            pos++
            return undefined
        } else if (k === '}') {
            pos++
            return undefined
        } else if ("-01234356789".includes(k)) {
            let r = ''
            while ("-01234356789.".includes(str[pos])) r += str[pos++]
            if (r.length >= 2 && r[0] === '0' && r[1] !== '.') throw 'Invalid input'
            if (r[r.length - 1] === '.') throw 'Invalid input'
            if (r.split('.').length > 2) throw 'Invalid input'
            return parseFloat(r)
        } else if (k === '"') {
            let r = ""
            pos++
            while (pos < str.length && str[pos] !== '"') r += str[pos++]
            if (pos === str.length) throw 'Invalid input'
            pos++
            return r
        } else if (k === 't') {
            pos += 4
            return true
        } else if (k === 'f') {
            pos += 5
            return false
        } else if (k === 'n') {
            pos += 4
            return null
        } else {
            throw 'Invalid input'
        }
    }

    let r = read_value(str)
    if (pos !== str.length || r === undefined) throw 'Invalid input'
    return r
}