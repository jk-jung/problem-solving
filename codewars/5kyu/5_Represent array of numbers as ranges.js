// Should return a string representing the ranges
function toRange(arr) {
    arr.sort((a, b) => a - b)

    let r = []
    for (let i = 0; i < arr.length; i++) {
        let n = r.length
        let x = arr[i]
        if (n == 0) r.push([x])
        else {
            let m = r[n - 1].length
            if (r[n - 1][m - 1] + 1 >= x) {
                if (m == 1) r[n - 1].push(x)
                else r[n - 1][m - 1] = x
            } else r.push([x])
        }
    }

    r = r.map(x => x.join('_')).join(',')
    return r
}

// Should return an array
function toArray(str) {
    if (str === '') return []

    r = []
    for (let x of str.split(',')) {
        if (x.indexOf('_') != -1) {
            let a = parseInt(x.split('_')[0])
            let b = parseInt(x.split('_')[1])
            for (let i = a; i <= b; i++) r.push(i)
        } else {
            r.push(parseInt(x))
        }
    }
    r.sort((a, b) => a - b)
    return r
}
