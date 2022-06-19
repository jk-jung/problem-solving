function maxSum(root) {
    if (root)
        return root.value + Math.max(maxSum(root.left), maxSum(root.right));
    else return 0
}