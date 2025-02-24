function split(arr, prop) {
    return [
        arr.filter(x => x[prop]),
        arr.filter(x => !x[prop])
    ]
}