/*
A Node has the following properties:
var data; // A number or string.
Node left; // Undefined if there is no left child.
Node right; // Undefined if there is no right child.
*/

// 1.) Root node, 2.) traverse left subtree, 3.) traverse right subtree.
function preOrder(node, r = []) {
    if (!node) return r
    r.push(node.data)
    preOrder(node.left, r)
    preOrder(node.right, r)
    return r
}

// 1.) Traverse left subtree, 2.) root node, 3.) traverse right subtree.
function inOrder(node, r = []) {
    if (!node) return r
    inOrder(node.left, r)
    r.push(node.data)
    inOrder(node.right, r)
    return r
}

// 1.) Traverse left subtree, 2.) traverse right subtree, 3.) root node.
function postOrder(node, r = []) {
    if (!node) return r
    postOrder(node.left, r)
    postOrder(node.right, r)
    r.push(node.data)
    return r
}