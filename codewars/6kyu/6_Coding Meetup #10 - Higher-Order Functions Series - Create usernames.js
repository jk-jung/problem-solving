function addUsername(list) {
    let y = new Date().getFullYear()
    list.forEach(x => {
        x.username = x.firstName.toLowerCase() + x.lastName[0].toLowerCase() + (y - x.age).toString()
    })
    return list
}