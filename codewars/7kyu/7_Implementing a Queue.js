var Queue = function() {
    this.v = []
    // implement your Queue constructor here
};

Queue.prototype.enqueue = function(item) {
    this.v.push(item)
    // add item to the queue
};

Queue.prototype.dequeue = function() {
    return this.v.shift()
    // remove item from the front of the queue and return its value
};

Queue.prototype.size = function() {
    return this.v.length
    // return number of items in queue so far
};