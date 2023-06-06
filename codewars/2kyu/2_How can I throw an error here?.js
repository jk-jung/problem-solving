function bang() {
    let m = 'Just thro' + 'w like this!'
    try {
        abc()
    }
    catch (e) {
        (function*(){})()['th' + 'row'](
            new e.__proto__.__proto__.constructor(m)
        )
    }
}