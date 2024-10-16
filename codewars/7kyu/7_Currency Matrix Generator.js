function generateCurrencyMatrix(c)
{

    const  a = ["EUR", "GBP", "AUD", "NZD", "USD", "CAD", "CHF", "JPY"]
    const r = []
    for(let x of a) {
        const i1 = a.indexOf(x)
        const i2 = a.indexOf(c)
        if(i1 < i2)r.push(x + c)
        else if(i1 > i2)r.push(c + x)
    }
    return r;
}
