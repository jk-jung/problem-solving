function createFunctions(n) {
    var callbacks = [];
    var t = (x) => () => x
    for (var i=0; i<n; i++) {
        callbacks.push(t(i))
    }

    return callbacks;
}