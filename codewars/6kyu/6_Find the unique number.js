function findUnique(n) {
    n.sort()
    for (let i = 0; i < n.length; i += 2) {
        if (n[i] !== n[i + 1]) return n[i]
    }
}