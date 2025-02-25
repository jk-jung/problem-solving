Object.defineProperty(Array.prototype, 'numberOfOccurrences',{
    value : function numberOfOccurrences(element) {
        return this.reduce((x, y) => x + (y == element), 0)
    }
});