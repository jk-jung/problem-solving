Array.prototype.size = function() {
    let r = 0
    this.forEach(x => r++)
    return r
  };