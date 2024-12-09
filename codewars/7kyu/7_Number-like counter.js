class Counter {
    constructor() {
        this.value = 0;
    }

    incr() {
        this.value += 1;
    }


    valueOf() {
        return this.value;
    }

    toString() {
        return String(this.value);
    }
}