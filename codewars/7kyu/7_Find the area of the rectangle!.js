function area(d,l){
    if (d < l) return 'Not a rectangle'
    return Math.round((d * d - l * l) ** .5 * l * 100) / 100
}