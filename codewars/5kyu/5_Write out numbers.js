let d2e = {
    0: 'zero',
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
    10: 'ten',
    11: 'eleven',
    12: 'twelve',
    13: 'thirteen',
    14: 'fourteen',
    15: 'fifteen',
    16: 'sixteen',
    17: 'seventeen',
    18: 'eighteen',
    19: 'nineteen',
    20: 'twenty',
    30: 'thirty',
    40: 'forty',
    50: 'fifty',
    60: 'sixty',
    70: 'seventy',
    80: 'eighty',
    90: 'ninety',
}
let base = [
    'quadrillion',
    'trillion',
    'billion',
    'million',
    'thousand',
    '',
]

function number2words(n) {
    let r = [], b = 1000000000000000
    for (let i = 0; i < 6; i++) {
        let t = Math.floor(n / b)
        r.push(t);
        n -= t * b
        b = Math.floor(b / 1000)
    }

    let to_s = (x, i) => {
        if (x === 0) return ''
        let a100 = d2e[Math.floor(x / 100)]
        let a10 = d2e[x % 100]

        if (!a10) a10 = d2e[Math.floor(x % 100 / 10) * 10] + '-' + d2e[x % 10]
        if (a10 === 'zero') a10 = ''
        if (a100 !== 'zero') a100 += ' hundred'
        else a100 = ''

        return ((a100 + ` ${a100 && a10 ? '' : ''}` + a10).trim() + ' ' + base[i]).trim()
    }

    let rr = r.map(to_s)
    let nn = ''
    for (let i = 0; i < rr.length; i++) {
        if (rr[i] === '') continue
        nn += ' ' + rr[i]
    }
    nn = nn.trim()
    if (nn === '') nn = 'zero'

    return nn
}