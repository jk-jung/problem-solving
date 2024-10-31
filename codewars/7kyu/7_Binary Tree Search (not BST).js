function search(n, root) {
    return root && (root.value === n || search(n, root.left) || search(n, root.right)) || false
}