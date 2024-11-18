/* Predefined object for list nodes

function Node(data, next = null) {
  this.data = data;
  this.next = next;
}

*/

function getKthLastElement(head, k) {
    let r = []
    while(head) {
        r.push(head)
        head = head.next
    }
    return r[r.length - k - 1]
    // head is the first Node in the list.
    // k is the 0-based index as counted from the end of the list.

    // return the list element corresponding to the index k
    // e.g.
    //   if k === 0 return the last element
    //   if k === 1 return the penultimate element
}