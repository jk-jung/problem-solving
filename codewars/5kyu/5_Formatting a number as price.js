var numberToPrice = function(n) {
    if (parseFloat(n) != n) return 'NaN'

    n = n.toLocaleString()
    if(!n.includes('.')) n += '.00'
    n += '00'

    while(n[n.length - 3] != '.') n = n.substr(0, n.length - 1)
    return n
}