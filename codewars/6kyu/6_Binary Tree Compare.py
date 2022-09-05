# return True if the two binary trees rooted and a and b are equal in value and structure
# return False otherwise
def compare(a, b):
    if a is None and b is None:
        return True

    if a is None or b is None:
        return False

    if a.val != b.val:
        return False

    return compare(a.left, b.left) and compare(a.right, b.right)