function sortArray(a1, a2) {
    return a2.sort((x, y) => {
        let i = a1.findIndex(k => k[0] == x[0])
        let j = a1.findIndex(k => k[0] == y[0])
        return i - j
    })
}