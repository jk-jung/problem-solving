/**
 * Your solution
 * @date JS Date object
 **/
function solution(d){
    let t = (d.getMonth()+1).toString() + d.getDate().toString() + d.getFullYear().toString()
    let r = 0
    for (let x of t) {
        r += parseInt(x)
        if(r >= 10) r = r % 10 + 1
    }
    return r
}