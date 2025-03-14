const transform = (s) => {
    let r = s.split("").filter((x, i) => s.indexOf(x) == i).map(x => `${x}${s.split("").filter(y=>x==y).length}`).join("")

    return r.replace(/1/gi, '')
}