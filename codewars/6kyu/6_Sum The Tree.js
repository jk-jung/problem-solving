// return the sum of all values in the tree, including the root
function sumTheTreeValues(t){
    let r = t.value
    if(t.left) r  += sumTheTreeValues(t.left)
    if(t.right) r  += sumTheTreeValues(t.right)

    return r
}