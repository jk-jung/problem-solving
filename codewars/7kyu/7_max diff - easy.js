function maxDiff(a) {
    if (a.length === 0) return 0
    return Math.max(...a) - Math.min(...a)
};