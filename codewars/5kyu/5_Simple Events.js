class Event {
    constructor() {
        this.fs = []
    }

    subscribe(x) {
        this.fs.push(x)
    }

    emit(...args) {
        this.fs.forEach(x => x(...args))
    }

    unsubscribe(x) {
        this.fs = this.fs.filter(y => y !== x)
    }

}
