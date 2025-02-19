function removeDuplication(a) {
    return a.filter(x => a.reduce((s, y) => (x == y) + s, 0) == 1)
}