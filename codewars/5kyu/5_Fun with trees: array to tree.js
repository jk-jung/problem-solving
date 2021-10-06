function arrayToTree(array) {
    let nodes = [], n = array.length
    if (n === 0) return

    for(let x of array) nodes.push(new TreeNode(x))
    for(let i=0;i<n;i++){
        let l = i * 2 + 1
        let r = i * 2 + 2
        if(l < n)nodes[i].left = nodes[l]
        if(r < n)nodes[i].right = nodes[r]
    }
    return nodes[0]
};