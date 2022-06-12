function compose() {
    let fs = arguments
    return (x) => {
        for(let i = fs.length - 1; i>=0;i--)
            x = fs[i](x)
        return x
    }
}