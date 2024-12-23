// return the magic index
function findMagic(arr){
    r =  arr.filter((x, i) => x == i)[0]
    return r === undefined ? -1 : r
}