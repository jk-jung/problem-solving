function increasingSequence(arr) {
    let d = {0: 0}
    let from = {0: -1}
    let r = arr.length - 1, r_idx = 0
    for (let i = 1; i < arr.length; i++) {
        d[i] = i
        for (let j = 0; j < i; j++) {
            if (arr[j] < arr[i] && d[i] > d[j] + i - j - 1) {
                d[i] = d[j] + i - j - 1
                from[i] = j
            }
        }
        if (r > d[i] + arr.length - i - 1) {
            r = d[i] + arr.length - i - 1
            r_idx = i
        }
    }

    let r_arr = []
    while (r_idx >= 0) {
        r_arr.push(arr[r_idx])
        r_idx = from[r_idx]
    }
    return r_arr.reverse()
}
