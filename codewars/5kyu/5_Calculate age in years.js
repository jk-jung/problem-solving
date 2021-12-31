/**
 * Return the difference between a birthdate and an optional "now" date, in years
 *
 * @param {Date} birthDate
 * @param {Date} nowDate
 * @return  {Number}
 */
function getAge(a, b) {
    if (b === undefined) b = new Date()
    let flag = 1
    if (a > b) {
        let t = b
        b = a
        a = t
        flag = -1
    }

    let ay = a.getFullYear()
    let by = b.getFullYear()
    let aa = a.getMonth() * 100 + a.getDate()
    let bb = b.getMonth() * 100 + b.getDate()

    let dif = by - ay
    if(aa > bb) dif --
    return flag * dif
}