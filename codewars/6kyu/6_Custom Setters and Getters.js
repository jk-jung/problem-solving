class Archiver {
    constructor() {
        this.archive = [];
        this._temperature = null;
    }

    get temperature() {
        return this._temperature
    }

    set temperature(t) {
        this.archive.push({'date': new Date(), 'val': t});
        this._temperature = t;
    }

    getArchive() {
        return this.archive;
    };
}