function oddOrEven(array) {
    return array.reduce((x, y) => x + y, 0) % 2 ? 'odd' : 'even'
}