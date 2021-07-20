let float2bin = function (input) {
    input = parseFloat(input)
    let sign = input < 0 ? '1' : '0'
    if (input < 0) input = -input
    let a = parseInt(input)
    let b = input - a
    let exp, frac

    if (a > 0) {
        a = a.toString(2).substr(1)
        b = b.toString(2).split('.')[1] || ''

        exp = (a.length + 127).toString(2).padStart(8, '0')
        frac = (a + b).padEnd(23, '0').substring(0, 23)
    } else {
        b = b.toString(2).split('.')[1]
        let idx = b.indexOf('1') + 1
        exp = (127 - idx).toString(2).padStart(8, '0')
        frac = b.substring(idx).padEnd(23, '0').substring(0, 23)
    }

    return sign + exp + frac
}
