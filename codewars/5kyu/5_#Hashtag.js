function getHashtags(post) {
    let r = []
    for (let x of post.split(' ')) {
        if (x[0] != '#') continue
        while (x.length > 1 && x[0] == '#') x = x.substr(1)
        if (x.includes('#')) continue
        if (x[0].match(/[a-zA-Z]/)) r.push(x)
    }
    return r
}