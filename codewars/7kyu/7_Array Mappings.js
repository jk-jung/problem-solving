Array.prototype.map = function(callback, thisArg) {
    const o = Object(this);
    const len = o.length;
    let r = []
    for (let i = 0; i < len; i++) {
        if (i in o)
            r[i] = callback.call(thisArg, o[i], i, o);

    }
    return r;
};