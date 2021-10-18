// TODO: implement 'mergesorted'
// test ensures: a and b are both arrays, consisting entirely of integers...
//...,both arrays are sorted and contain at least 1 integer.
// ALSO: the Array.sort function has been disabled for this excercise.
function mergesorted(a, b) {
    let n = a.length
    let m = b.length
    let i = 0
    let j = 0

    let r = []
    while(i != n || j != m) {
        if(i == n || a[i] > b[j]) r.push(b[j++])
        else r.push(a[i++])
    }

    return r
}
