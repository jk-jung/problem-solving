function invertHash(hash) {
    return Object.fromEntries(Object.entries(hash).map(([x, y]) => [y, x]))
}