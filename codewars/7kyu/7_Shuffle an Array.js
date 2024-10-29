function shuffle(arr) {
    let r = []
    for(let i=0;i<arr.length;i++){
        let a = Math.floor(Math.random() * arr.length)
        let b = Math.floor(Math.random() * arr.length)
        let t = arr[a]
        arr[a] = arr[b]
        arr[b] = t
    }
    return arr
}
