function solve(arr){
    arr = [...new Set(arr)]
    return arr.reduce((x, y) => x + y, 0)
};