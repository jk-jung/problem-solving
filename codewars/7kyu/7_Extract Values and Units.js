function valAndUnits(s) {
    const re = /([-.0-9]+)([^0-9]*)/;
    r = s.match(re)
    return {val: Number(r[1]), units: r[2].trim()}
}