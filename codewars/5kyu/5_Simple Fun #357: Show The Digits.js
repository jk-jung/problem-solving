function show(d, s) {
    d = d.split('')
    let st = {
        '0': [1, 0, 1, 1, 1, 1, 1],
        '1': [0, 0, 0, 0, 1, 0, 1],
        '2': [1, 1, 1, 0, 1, 1, 0],
        '3': [1, 1, 1, 0, 1, 0, 1],
        '4': [0, 1, 0, 1, 1, 0, 1],
        '5': [1, 1, 1, 1, 0, 0, 1],
        '6': [1, 1, 1, 1, 0, 1, 1],
        '7': [1, 0, 0, 0, 1, 0, 1],
        '8': [1, 1, 1, 1, 1, 1, 1],
        '9': [1, 1, 1, 1, 1, 0, 1],
    }

    let h = (v) => {
        let t = ''
        for (let x of v) t += ` ${(x ? '-' : ' ').repeat(s)} `
        return t
    }
    let w = (v) => {
        let t = ''
        for (let x of v)
            t += `${x[0] ? '|' : ' '}${' '.repeat(s)}${x[1] ? '|' : ' '}`
        return t
    }
    let r = []
    r.push(h(d.map(x => st[x][0])))
    for (let i = 0; i < s; i++)
        r.push(w(d.map(x => [st[x][3], st[x][4]])))
    r.push(h(d.map(x => st[x][1])))
    for (let i = 0; i < s; i++)
        r.push(w(d.map(x => [st[x][5], st[x][6]])))
    r.push(h(d.map(x => st[x][2])))

    return r.map(x => x.trimEnd()).join('\n')
}