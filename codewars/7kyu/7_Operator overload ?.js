var Foo = function(value) {
    this.val = value;
    this.valueOf = function() {
        return this.val;
    }
}