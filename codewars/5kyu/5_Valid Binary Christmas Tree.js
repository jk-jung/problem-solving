function isValidTree(tree, root=true){
    if(root && tree.ornament !== 'star') return false
    let child = !!(tree.left || tree.right)
    if(!root && child && tree.color !== 'red') return false
    if(!root && !child && tree.color !== 'blue') return false

    let r = true
    if(tree.left) r = r && isValidTree(tree.left, false)
    if(tree.right) r = r && isValidTree(tree.right, false)
    return r
}